/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:17:12 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:32:45 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdf	*g_my;

void			inner_d(t_node ***nd, t_fdf *my)
{
	double x0;
	double x1;
	double y1;
	double y0;

	g_my = my;
	x0 = nd[0][0]->x - g_my->shag / 2;
	x1 = nd[0][nd[0][0]->l - 1]->x + g_my->shag / 2;
	y0 = nd[0][0]->y + g_my->shag / 2;
	y1 = nd[nd[0][0]->h - 1][0]->y - g_my->shag / 2;
	while (x0 <= x1)
	{
		y1 = nd[nd[0][0]->h - 1][0]->y - g_my->shag / 2;
		while (y1 <= y0)
		{
			mlx_pixel_put(g_my->mlx, g_my->win, x0, y1, 0x999415);
			mlx_pixel_put(g_my->mlx, g_my->win, x1, y1, 0x999415);
			y1++;
		}
		x0 = x0 + my->shag;
	}
}

void			draw2(t_node ***nd, t_fdf *my)
{
	double x0;
	double x1;
	double y1;
	double y0;

	g_my = my;
	x0 = nd[0][0]->x - g_my->shag / 2;
	x1 = nd[0][nd[0][0]->l - 1]->x + g_my->shag / 2;
	y0 = nd[0][0]->y + g_my->shag / 2;
	y1 = nd[nd[0][0]->h - 1][0]->y - g_my->shag / 2;
	while (y1 <= y0)
	{
		x0 = nd[0][0]->x - g_my->shag / 2;
		while (x0 <= x1)
		{
			mlx_pixel_put(g_my->mlx, g_my->win, x0, y0, 0x999415);
			mlx_pixel_put(g_my->mlx, g_my->win, x0, y1, 0x999415);
			x0++;
		}
		y1 = y1 + my->shag;
	}
	inner_d(nd, my);
}
