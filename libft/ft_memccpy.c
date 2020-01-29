/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:44:22 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/02 19:52:18 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*start_d;
	const unsigned char	*start_s;

	start_d = (unsigned char *)dest;
	start_s = (const unsigned char *)src;
	while (n != 0)
	{
		*start_d = *start_s;
		start_d++;
		if (*start_s == (unsigned char)c)
			return (start_d);
		start_s++;
		n--;
	}
	return (NULL);
}
