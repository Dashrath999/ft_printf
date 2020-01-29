/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:46:52 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 18:34:15 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 **Fonction qui prends la char * de ce qu'il faut convertir
 **et qui en retire les infos necéssaire
*/

t_spec		get_info(char *s, t_spec info)
{
	int		i;
	char	*size_tmp;

	i = 0;
	while (s[i] && is_spec_with_pr(s[i]))
	{
		if (is_option(s[i]))
			info = get_info_option(s, &i, info);
		else if (ft_isdigit(s[i]) || s[i] == '.')
			info = get_info_wdth_n_prec(s, &i, info);
		else if (s[i] == 'l' || s[i] == 'L' || s[i] == 'h')
		{
			size_tmp = get_info_size(s, &i);
			if (size_tmp == NULL)
			{
				info.mal_error = 1;
				return (info);
			}
			ft_strcpy(info.taille, check_error_flag(info, size_tmp));
			free(size_tmp);
		}
		else if (is_type_with_pr(s[i]))
			info.type = s[i];
		i++;
	}
	return (info);
}

t_spec		get_info_option(char *s, int *i, t_spec info)
{
	while (is_option(s[*i]))
	{
		if (s[*i] == '#')
			info.f_hash = 1;
		else if (s[*i] == '0')
			info.f_zero = 1;
		else if (s[*i] == '-')
			info.f_minus = 1;
		else if (s[*i] == '+')
			info.f_plus = 1;
		else if (s[*i] == ' ')
			info.f_space = 1;
		*i = *i + 1;
	}
	*i = *i - 1;
	return (info);
}

t_spec		get_info_wdth_n_prec(char *s, int *i, t_spec info)
{
	if (ft_isdigit(s[*i]))
	{
		info.width = ft_atoi(&s[*i]);
		while (s[*i] != '.' && ft_isdigit(s[*i]))
			*i = *i + 1;
	}
	while (s[*i] == '.')
	{
		*i = *i + 1;
		if (ft_isdigit(s[*i]) == 1)
			info.precision = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]) == 1)
			*i = *i + 1;
	}
	*i = *i - 1;
	return (info);
}

char		*get_info_size(char *s, int *i)
{
	int		j;
	int		n;
	char	*size_tmp;

	j = *i;
	n = 0;
	while ((s[*i] == 'l' || s[*i] == 'L' || s[*i] == 'h') && n < 2)
	{
		*i = *i + 1;
		if (s[*i - 1] == 'L')
			break ;
		n++;
	}
	size_tmp = ft_strsub(s, j, *i - j);
	*i = *i - 1;
	return (size_tmp);
}
