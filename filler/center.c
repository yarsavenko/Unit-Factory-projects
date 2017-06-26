/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:37:17 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 17:12:09 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_center2(t_node ***node, t_fdf *my, int a)
{
	int ncen[2];

	ncen[0] = node[0][0]->l / 2;
	ncen[1] = node[0][0]->h / 2;
	while (ncen[1] - a >= 0)
	{
		node[ncen[1] - a][0]->x = node[ncen[1] - a + 1][0]->x;
		node[ncen[1] - a][0]->y = node[ncen[1] - a + 1][0]->y + my->shag;
		a++;
	}
}

int		find_center(t_node ***node, t_fdf *my, int a)
{
	int ncen[2];

	ncen[0] = node[0][0]->l / 2;
	ncen[1] = node[0][0]->h / 2;
	if (node[0][0]->l % 2 != 0)
		node[ncen[1]][ncen[0]]->x = my->x / 2;
	else
		node[ncen[1]][ncen[0]]->x = my->x / 2 + my->shag;
	if (node[0][0]->h % 2 != 0)
		node[ncen[1]][ncen[0]]->y = my->y / 2;
	else
		node[ncen[1]][ncen[0]]->y = my->y / 2;
	a = 1;
	while (ncen[0] - a >= 0)
	{
		node[ncen[1]][ncen[0] - a]->x = node[ncen[1]][ncen[0] - a + 1]->x -
			my->shag;
		node[ncen[1]][ncen[0] - a]->y = node[ncen[1]][ncen[0] - a + 1]->y;
		a++;
	}
	find_center2(node, my, 1);
	fill_xnode(node, my->angle, my->shag, my->xangle);
	return (0);
}
