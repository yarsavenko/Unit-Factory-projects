/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:10:15 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 19:37:40 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	swap(t_node ***nd)
{
	unsigned int	buff;
	int				a;
	int				b;
	int				c;
	int				d;

	a = 0;
	b = nd[0][0]->h - 1;
	while (a < b)
	{
		c = 0;
		while (c < nd[0][0]->l)
		{
			buff = nd[a][c]->color;
			nd[a][c]->color = nd[b][c]->color;
			nd[b][c]->color = buff;
			c++;
		}
		a++;
		b--;
	}
}
