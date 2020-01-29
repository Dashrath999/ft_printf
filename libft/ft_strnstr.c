/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:05:48 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/05 05:19:54 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*j;
	char	*k;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len--)
	{
		if (*haystack == *needle)
		{
			i = len;
			j = (char *)haystack + 1;
			k = (char *)needle + 1;
			while (i-- && *j && *k && *j == *k)
			{
				j++;
				k++;
			}
			if (!*k)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
