/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:55:56 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:20:38 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		take_mod(char *str, t_print **my)
{
	int mod;
	int a;

	a = 0;
	mod = 0;
	while (str[a] && (is_flag(str[a]) || str[a] == '.' ||
		is_digit(str[a]) || is_mod(str[a])))
	{
		if (str[a] == 'h')
		{
			if (mod == 2 && mod != 1 && mod != 4)
				mod = 3;
			else if (mod != 1 && mod != 4)
				mod = 2;
		}
		if (str[a] == 'z' && mod == 0)
			mod = 4;
		if (str[a] == 'j')
			mod = 1;
		if (str[a] == 'l' && mod != 4)
			mod = 1;
		a++;
	}
	(*my)->mod = mod;
}
