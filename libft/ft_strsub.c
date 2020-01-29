/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:05:10 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/06/26 16:05:27 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trc;
	int		i;

	if (!s)
		return (NULL);
	trc = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!trc)
		return (NULL);
	trc[len] = '\0';
	while (len != 0)
	{
		trc[i] = s[start + i];
		i++;
		len--;
	}
	return (trc);
}
