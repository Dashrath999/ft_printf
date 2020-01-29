/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj_to_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:42:03 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/02/07 15:01:37 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_maj_to_min(char *str)
{
	int i;
	char *sub;

	i = 0;
	sub = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			sub[i] = str[i] + 32;
		else
			sub[i] = str[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
