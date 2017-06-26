/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:17:12 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:20:38 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdf	*g_my;

static void			draw_sq(t_node *node)
{
	int a;
	int b;
	int c;
	int d;

	c = node->y + g_my->shag / 2;
	d = node->y - g_my->shag / 2;
	b = node->x + g_my->shag / 2;
	while (d < c)
	{
		a = node->x - g_my->shag / 2;
		while (a < b)
		{
			mlx_pixel_put(g_my->mlx, g_my->win, a, d, node->color);
			a++;
		}
		d++;
	}
}

void				draw(t_node ***nd, t_fdf *my)
{
	int a;
	int b;
	int col;

	a = 0;
	g_my = my;
	mlx_string_put(my->mlx, my->win, nd[0][0]->x - my->shag / 2, 50,
	0x1B2984, "Player X");
	mlx_string_put(my->mlx, my->win, nd[0][0]->x - my->shag / 2, 70,
	0x167C18, "Player 0");
	while (a < nd[0][0]->h)
	{
		b = 0;
		while (b < nd[0][0]->l)
		{
			draw_sq(nd[a][b]);
			b++;
		}
		a++;
	}
	draw2(nd, my);
}
