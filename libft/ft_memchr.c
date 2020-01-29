/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:53:14 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/09 15:19:15 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *start;

	start = (unsigned char *)str;
	while (n != 0)
	{
		if (*start == (unsigned char)c)
			return ((unsigned char *)start);
		start++;
		n--;
	}
	return (NULL);
}
