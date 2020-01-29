/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:18:23 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 18:27:39 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**remet la width et la precision a 0 si elle depasse la taille d'un int
**trouver une solution dans le cas %.08i la precision se remet a 0 a la place
**d'etre a 8
*/

t_spec			check_error_width_n_prec(t_spec info, char *s)
{
	int		i;
	int		j;
	char	*sub;
	char	*temp;

	check_i_j(s, &i, &j);
	if (ft_strequ(temp = ft_itoa(info.width),
				sub = ft_strsub(s, i, j - i)) == 0)
		info.width = 0;
	free(sub);
	free(temp);
	if (s[j++] == '.')
	{
		i = j;
		while (ft_isdigit(s[i]))
			i++;
		if (ft_strequ(temp = ft_itoa(info.precision),
		sub = ft_strsub(s, j, i - j)) == 0 || i == j)
			info.precision = 0;
		free(sub);
		free(temp);
	}
	free(s);
	return (check_error_option(info));
}

void			check_i_j(char *s, int *i, int *j)
{
	*i = 0;
	while (is_option(s[*i]))
		*i = *i + 1;
	*j = *i;
	while (ft_isdigit(s[*j]))
		*j = *j + 1;
}

/*
 **remet a 0 les options au besoin
*/

t_spec			check_error_option(t_spec info)
{
	if (info.f_zero && info.f_minus)
		info.f_zero = 0;
	if (info.f_plus && info.f_space)
		info.f_space = 0;
	if (info.type == 's')
	{
		info.f_plus = 0;
		info.f_space = 0;
	}
	if (info.type == '%')
		info.f_space = 0;
	if (info.precision != -1 && (info.type == 'd' || info.type == 'i'
	|| info.type == 'o' || info.type == 'u' || info.type == 'x'
	|| info.type == 'X'))
		info.f_zero = 0;
	if (!is_type_with_pr(info.type))
		info.type = 0;
	return (info);
}

/*
 **conserve la plus grande taille pour info.taille
*/

char			*check_error_flag(t_spec info, char *size_tmp)
{
	if (!ft_strcmp(size_tmp, "ll") || !ft_strcmp(info.taille, "ll"))
		return ("ll");
	if (!ft_strcmp(size_tmp, "l") || !ft_strcmp(info.taille, "l"))
		return ("l");
	if (!ft_strcmp(size_tmp, "L") || !ft_strcmp(info.taille, "L"))
		return ("L");
	if (!ft_strcmp(size_tmp, "h") || !ft_strcmp(info.taille, "h"))
		return ("h");
	if (!ft_strcmp(size_tmp, "hh") || !ft_strcmp(info.taille, "hh"))
		return ("hh");
	return ("er");
}
