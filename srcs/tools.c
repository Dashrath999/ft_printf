/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:27 by mpizzaga          #+#    #+#             */
/*   Updated: 2019/02/15 15:54:50 by mpizzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_option(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'c' || c == 'f')
		return (1);
	return (0);
}

int		is_type_with_pr(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'c' || c == 'f' || c == '%')
		return (1);
	return (0);
}

int		is_spec(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'c' || c == 'f' || c == '#' || c == '.'
	|| c == '+' || c == '-' || c == ' ' || ft_isdigit(c) || c == 'h'
	|| c == 'l' || c == 'L')
		return (1);
	return (0);
}

int		is_spec_with_pr(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'x' || c == 'X' || c == 'c' || c == 'f' || c == '#' || c == '.'
	|| c == '+' || c == '-' || c == ' ' || ft_isdigit(c) || c == 'h'
	|| c == 'l' || c == 'L' || c == '%')
		return (1);
	return (0);
}
