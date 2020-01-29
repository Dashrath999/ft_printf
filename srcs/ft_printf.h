/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:00:29 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 20:22:43 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_spec
{
	char			type;
	int				f_hash;
	int				f_zero;
	int				f_minus;
	int				f_plus;
	int				f_space;
	int				width;
	int				precision;
	int				probleme;
	char			taille[2];
	int				mal_error;
}					t_spec;

int					ft_printf(const char *format, ...);
void				get_spec(const char *format, int *i, va_list ap,
					int *count);
void				malloc_error(int *count);

int					is_spec(char c);
int					is_option(char c);
int					is_type(char c);
int					is_type_with_pr(char c);
int					is_spec_with_pr(char c);

void				init_info(t_spec *info);
void				init_types(int (*f[256]) (va_list ap, t_spec info));

t_spec				get_info(char *spec, t_spec info);
t_spec				get_info_option(char *s, int *i, t_spec info);
t_spec				get_info_wdth_n_prec(char *s, int *i, t_spec info);
char				*get_info_size(char *s, int *i);

t_spec				check_error_option(t_spec info);
t_spec				check_error_width_n_prec(t_spec info, char *s);
void				check_i_j(char *s, int *i, int *j);
char				*check_error_flag(t_spec info, char *size_tmp);

int					convert(va_list ap, t_spec info);
void				print_width(t_spec *info, int *count);
int					get_number_len(long long n);
void				print_sign(t_spec *info, int *count, int sign);

int					f_s(va_list ap, t_spec info);
void				convert_s(char *str, t_spec *info, int *count);

int					f_d_i(va_list ap, t_spec info);
void				convert_d_i(long long n, t_spec *info, int *count
		, int sign);
void				get_width(t_spec *info, int len, int fill);
void				convert_d_i_zero_prec(t_spec *info, int *count);


int					f_o(va_list ap, t_spec info);
void				convert_o(char *str, t_spec *info, int *count);
void				convert_o_u_zero_prec(t_spec *info, int *count);

int					f_u(va_list ap, t_spec info);
void				convert_u(char *str, t_spec *info, int *count);

int					f_percent(va_list ap, t_spec info);

int					f_c(va_list ap, t_spec info);
void				convert_c(char c, t_spec *info, int *count);

int					f_f(va_list ap, t_spec info);

int					f_x(va_list ap, t_spec info);
void				convert_x(char *str, t_spec *info, int *count);
void				convert_x_bigx_zero_prec(t_spec *info, int *count);

int					f_no_type(va_list ap, t_spec info);
#endif
