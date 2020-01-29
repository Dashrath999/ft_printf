/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:51:22 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 18:32:10 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_s(va_list ap, t_spec info)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	convert_s(str, &info, &count);
	return (count);
}

void	convert_s(char *str, t_spec *info, int *count)
{
	int len;

	len = ft_strlen(str);
	if (info->width)
		info->width = (info->precision >= 0 && info->precision < len) ?
			info->width - info->precision : info->width - len;
	if (!info->f_minus && info->width > 0)
		print_width(info, count);
	if (info->precision >= 0 && info->precision < len)
	{
		ft_putnstr(str, info->precision);
		*count = *count + info->precision;
	}
	else
	{
		ft_putstr(str);
		*count = *count + len;
	}
	if (info->f_minus && info->width > 0)
		print_width(info, count);
}
