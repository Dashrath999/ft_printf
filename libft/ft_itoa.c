/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:12:06 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/01/02 16:45:20 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		temp_n;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
