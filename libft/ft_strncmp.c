/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:04:01 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/09 15:02:36 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 == *str2 && n--)
	{
		if (*str1 == '\0' || *str2 == '\0')
			break ;
		str1++;
		str2++;
	}
	if (n == 0)
		return (0);
	return (int)((unsigned char)*str1 - (unsigned char)*str2);
}
