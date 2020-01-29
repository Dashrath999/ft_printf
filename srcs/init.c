/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:13:30 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 20:15:49 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 **fonction qui initialise le tableau
 **de pointeurs sur fonction pour les conversion
*/

void	init_types(int (*f[256]) (va_list ap, t_spec info))
{
	f[115] = f_s;
//	f[112] = f_p;
	f[100] = f_d_i;
	f[105] = f_d_i;
	f[111] = f_o;
	f[117] = f_u;
	f[120] = f_x;
//	f[88] = f_x_maj;
	f[99] = f_c;
//	f[102] = f_f;
	f[37] = f_percent;
	f[0] = f_no_type;
}

/*
 **fonction qui initialise la structure pour les infos a convertir a 0
*/

void	init_info(t_spec *info)
{
	info->f_hash = 0;
	info->f_zero = 0;
	info->f_minus = 0;
	info->f_plus = 0;
	info->f_space = 0;
	info->width = 0;
	info->precision = -1;
	info->taille[0] = '\0';
	info->type = '\0';
	info->mal_error = 0;
}

/*
 **fonction qui empeche le segfault en cas de types inconnu
*/

int		f_no_type(va_list ap, t_spec info)
{
	(void)ap;
	(void)info;
	return (-1);
}
