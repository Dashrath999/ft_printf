/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:15:57 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/09 18:27:04 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*sour;
	size_t		n;
	size_t		dest_len;

	dest = dst;
	sour = src;
	n = size;
	while (n-- && *dest != '\0')
		dest++;
	dest_len = dest - dst;
	n = size - dest_len;
	if (n == 0)
		return (dest_len + ft_strlen(src));
	while (*sour != '\0')
	{
		if (n != 1)
		{
			*dest++ = *sour;
			n--;
		}
		sour++;
	}
	*dest = '\0';
	return (dest_len + (sour - src));
}
