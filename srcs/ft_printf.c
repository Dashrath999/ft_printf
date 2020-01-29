/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:59:52 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/04/05 18:31:37 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (count < 0)
			return (-1);
		if (format[i] == '%')
			get_spec(format, &i, ap, &count);
		else
		{
			ft_putchar(format[i]);
			count++;
		}
	}
	va_end(ap);
	return (count);
}

/*
 **Fonction qui prends et renvoi ce qu'il faut convertir.
*/

void		get_spec(const char *format, int *i, va_list ap, int *count)
{
	int		j;
	char	*spec;
	t_spec	info;
	int		count_res;

	init_info(&info);
	j = *i + 1;
	*i = *i + 1;
	while (is_spec(format[*i]) && !is_type(format[*i]) && format[*i])
		*i = *i + 1;
	spec = ft_strsub(format, j, *i - (j - 1));
	if (!spec)
		return (malloc_error(count));
	info = check_error_width_n_prec(get_info(spec, info), spec);
	if (info.mal_error)
		return (malloc_error(count));
	if ((count_res = convert(ap, info)) < 0)
		return (malloc_error(count));
	*count = *count + count_res;
}

void	malloc_error(int *count)
{
	*count = -1;
	return ;
}
