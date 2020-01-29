/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:48:59 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 20:41:48 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_d_i(va_list ap, t_spec info)
{
	long long	n;
	int			count;
	int			sign;

	count = 0;
	if (ft_strequ(info.taille, "l"))
		n = (long)va_arg(ap, long);
	else if (ft_strequ(info.taille, "ll"))
		n = (long long)va_arg(ap, long long);
	else if (ft_strequ(info.taille, "h"))
		n = (short int)va_arg(ap, int);
	else if (ft_strequ(info.taille, "hh"))
		n = (signed char)va_arg(ap, int);
	else
		n = va_arg(ap, int);
	sign = (n >= 0) ? 0 : 1;
	if (sign)
		n = -n;
	if (info.precision == 0 && n == 0)
		convert_d_i_zero_prec(&info, &count);
	else
		convert_d_i(n, &info, &count, sign);
	return (count);
}

void	convert_d_i(long long n, t_spec *info, int *count, int sign)
{
	int len;
	int fill;

	len = get_number_len(n);
	fill = (info->f_plus || info->f_space || sign) ? 1 : 0;
	if (info->width)
		get_width(info, len, fill);
	if (fill && info->f_zero)
		print_sign(info, count, sign);
	if (!info->f_minus && info->width > 0)
		print_width(info, count);
	if (fill && !info->f_zero)
		print_sign(info, count, sign);
	while (info->precision > len)
	{
		ft_putchar('0');
		*count = *count + 1;
		info->precision--;
	}
	ft_putllnbr(n);
	*count = *count + len;
	if (info->f_minus && info->width > 0)
		print_width(info, count);
}

void	convert_d_i_zero_prec(t_spec *info, int *count)
{
	char fill;

	if (info->width && (info->f_plus || info->f_space))
	{
		info->width--;
		fill = (info->f_plus) ? '+' : ' ';
		*count = *count + 1;
	}
	if (info->width && !info->f_minus)
		print_width(info, count);
	if (fill)
		ft_putchar(fill);
	if (info->width && info->f_minus)
		print_width(info, count);
}

void	get_width(t_spec *info, int len, int fill)
{
	info->width = (info->precision >= 0 && info->precision > len) ?
	info->width - (info->precision - len) - len - fill
	: info->width - len - fill;
}
