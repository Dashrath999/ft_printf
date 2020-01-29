/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:43:01 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/04 14:47:06 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strnsub[](char *s, int start, int len)
{
	char	trc[len + 1];
	int		i;

	i = 0;
	trc[len] = '\0';
	while (len != 0 && s[start])
	{
		trc[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (trc);
}
