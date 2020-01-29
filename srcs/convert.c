/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:58:30 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 18:29:11 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert(va_list ap, t_spec info)
{
	int count;
	int (*f[256]) (va_list ap, t_spec info);

	init_types(f);
	count = f[(int)info.type](ap, info);
	return (count);
}

void	print_width(t_spec *info, int *count)
{
	char fill;

	fill = (info->f_zero) ? '0' : ' ';
	while (info->width--)
	{
		ft_putchar(fill);
		*count = *count + 1;
	}
	info->width++;
}

int		get_number_len(long long n)
{
	long long	i;
	int			len;
	int			sign;

	sign = (n < 0) ? 1 : 0;
	if (sign)
		n = -n;
	len = 0;
	i = n;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len + sign);
}

void	print_sign(t_spec *info, int *count, int sign)
{
	char fill;

	fill = (info->f_plus) ? '+' : ' ';
	if (sign)
		fill = '-';
	ft_putchar(fill);
	*count = *count + 1;
}
