/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:47:20 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/01/04 18:17:29 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int		find_len(unsigned long n)
{
	int i;

	i = 1;
	while ((n = n / 16) != 0)
		i++;
	return (i);
}

static char	hex_form(int n)
{
	char c;

	if (n > 9)
		c = 97 + (n - 10);
	else
		c = 48 + n;
	return (c);
}

char	*ft_hex( unsigned long n)
{
	char *res;
	int len;

	len = find_len(n);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	 while (n / 16 != 0)
	{
		res[len] = hex_form(n % 16);
		len--;
		n = n / 16;
	}
	 res[len] = hex_form(n % 16);
	 return (res);
}
