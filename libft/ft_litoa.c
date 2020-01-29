/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:12:06 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/03/21 18:29:20 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_litoa(long n)
{
	char	*str;
	long		temp_n;
	int		len;
	int		neg;

	if (n == -9223372036854775807 - 1)
		return(ft_strdup("-9223372036854775808"));
	len = 1;
	neg = n < 0;
	n = n < 0 ? -n : n;
	temp_n = n;
	while (temp_n / 10 > 0 && len++)
		temp_n /= 10;
	len = len + neg;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > neg)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
