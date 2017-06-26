/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_xnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:43:22 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 17:13:04 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_xnode(t_node ***node, int alpha, int shag, int balpha)
{
	int a;
	int b;

	a = 1;
	while (a < node[0][0]->h)
	{
		node[a][0]->x = node[a - 1][0]->x;
		node[a][0]->y = node[a - 1][0]->y - shag;
		a++;
	}
	a = 0;
	while (a < node[0][0]->h)
	{
		b = 1;
		while (b < node[0][0]->l)
		{
			node[a][b]->x = node[a][b - 1]->x + shag;
			node[a][b]->y = node[a][b - 1]->y;
			b++;
		}
		a++;
	}
}
