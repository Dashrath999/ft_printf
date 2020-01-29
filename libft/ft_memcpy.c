/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:53:36 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/02 19:51:58 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*start_d;
	const char	*start_s;

	start_d = (char *)dest;
	start_s = (const char *)src;
	while (n != 0)
	{
		*start_d = *start_s;
		start_d++;
		start_s++;
		n--;
	}
	return (dest);
}
