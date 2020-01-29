/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:14:59 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 20:48:19 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_u(va_list ap, t_spec info)
{
	int		count;
	char	*str;

	count = 0;
	if (ft_strequ(info.taille, "l"))
		str = ft_ulitoa((unsigned long)va_arg(ap, unsigned long));
	else if (ft_strequ(info.taille, "ll"))
		str = ft_ullitoa((unsigned long long)va_arg(ap, unsigned long long));
	else if (ft_strequ(info.taille, "h"))
		str = ft_litoa((unsigned short int)va_arg(ap, unsigned int));
	else if (ft_strequ(info.taille, "hh"))
		str = ft_litoa((unsigned char)va_arg(ap, unsigned int));
	else
		str = ft_litoa((unsigned int)va_arg(ap, unsigned int));
	if (!str)
		return (-1);
	if (info.precision == 0 && ft_atoi(str) == 0)
		convert_o_u_zero_prec(&info, &count);
	else
		convert_u(str, &info, &count);
	free(str);
	return (count);
}

void	convert_u(char *str, t_spec *info, int *count)
{
	int len;

	len = ft_strlen(str);
	if (info->width)
		get_width(info, len, 0);
	if (!info->f_minus && info->width > 0)
		print_width(info, count);
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
