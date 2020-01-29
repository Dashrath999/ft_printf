/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 14:18:21 by mpizzaga          #+#    #+#             */
/*   Updated: 2018/07/09 18:36:56 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(char const *s, char c)
{
	int		i;
	int		word;

	if (!s)
		return (0);
	i = 0;
	word = 0;
	while (*s != '\0')
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			i++;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (i);
}

static int		ft_get_word_len(char const *s, int c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	char	**str;

	words = ft_countword(s, c);
	if (!s || !(str = (char **)malloc(sizeof(char *) *
					(words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub((char *)s, 0, ft_get_word_len((char *)s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + ft_get_word_len((char *)s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
