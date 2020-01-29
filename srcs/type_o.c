/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:35:29 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 20:23:43 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_o(va_list ap, t_spec info)
{
	int					count;
	char				*str;

	count = 0;
	if (ft_strequ(info.taille, "l"))
		str = ft_oct((long)va_arg(ap, long));
	else if (ft_strequ(info.taille, "h"))
		str = ft_oct((unsigned short int)va_arg(ap, unsigned int));
	else if (ft_strequ(info.taille, "hh"))
		str = ft_oct((unsigned char)va_arg(ap, unsigned int));
	else if (ft_strequ(info.taille, "ll"))
		str = ft_oct((long long)va_arg(ap, long long));
	else
		str = ft_oct(va_arg(ap, unsigned int));
	if (!str)
		return (-1);
	if (info.precision == 0 && ft_atoi(str) == 0)
		convert_o_u_zero_prec(&info, &count);
	else
		convert_o(str, &info, &count);
	free(str);
	return (count);
}

void	convert_o(char *str, t_spec *info, int *count)
{
	int len;
	int fill;

	len = ft_strlen(str);
	fill = (info->f_hash && ft_atoi(str) != 0) ? 1 : 0;
	if (info->width)
		get_width(info, len, fill);
	if (!info->f_minus && info->width > 0)
		print_width(info, count);
	if (info->f_hash && !info->f_zero && ft_atoi(str) != 0
			&& info->precision <= len)
	{
		ft_putchar('0');
		*count = *count + 1;
	}
	while (info->precision > len)
	{
		ft_putchar('0');
		*count = *count + 1;
		info->precision--;
	}
	ft_putstr(str);
	*count = *count + len;
	if (info->f_minus && info->width > 0)
		print_width(info, count);
}

void	convert_o_u_zero_prec(t_spec *info, int *count)
{
	if (info->width)
		print_width(info, count);
}
