/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:04:20 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/01/04 18:08:16 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		find_len(unsigned long n)
{
	int i;

	i = 1;
	while ((n = n / 8) != 0)
		i++;
	return (i);
}

char	octal_form(int n)
{
	char c;

	c = 48 + n;
	return (c);
}

char	*ft_oct(unsigned long n)
{
	char *res;
	int len;
	len = find_len(n);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	while (n / 8 != 0)
	{
		res[len] = octal_form(n % 8);
		len--;
		n = n / 8;
	}
	res[len] = octal_form(n % 8);
	return (res);
}
