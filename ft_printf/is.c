/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:16:50 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 17:49:06 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_mod(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'd' || c == 'D' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'p' || c == 'i'
		|| c == 'c' || c == 'C' || c == 'b' || c == 'n')
		return (1);
	return (0);
}

int		is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
