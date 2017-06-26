/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:05:54 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:18:01 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		read_flag(char c, t_print **my)
{
	if (c == '-')
		(*my)->minus = 1;
	if (c == '+')
		(*my)->plus = 1;
	if (c == '#')
		(*my)->resh = 1;
	if (c == ' ')
		(*my)->prob = 1;
	if (c == '0')
		(*my)->nolik = 1;
}

void		init_my(t_print **my)
{
	(*my)->minus = 0;
	(*my)->plus = 0;
	(*my)->resh = 0;
	(*my)->nolik = 0;
	(*my)->prob = 0;
	(*my)->mn_pl = -1;
	(*my)->type = 0;
	(*my)->sss = 0;
	(*my)->to4 = -1;
	(*my)->mod = 0;
	(*my)->ret = "";
	(*my)->is_s = 0;
	(*my)->is_s_n = 0;
	(*my)->is_c_n = 0;
}
