/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:17:12 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 15:29:17 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*g_my;

static void		swapd(double *x, double *y)
{
	double buff;

	buff = *x;
	*x = *y;
	*y = buff;
}

void			print_x(t_node *n0, t_node *n1, int x, int y)
{
	double x0;
	double x1;
	double y0;
	double y1;

	y0 = n0->y - n0->z;
	y1 = n1->y - n1->z;
	x0 = n0->x;
	x1 = n1->x;
	if (x0 > x1)
	{
		swapd(&x0, &x1);
		swapd(&y0, &y1);
	}
	x = x0;
	y = y0;
	while (x <= x1)
	{
		mlx_pixel_put(g_my->mlx, g_my->win, x, y, n0->color);
		x++;
		y = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
	}
}

void			print_y(t_node *n0, t_node *n1, int x, int y)
{
	double x0;
	double x1;
	double y0;
	double y1;

	y0 = n0->y - n0->z;
	y1 = n1->y - n1->z;
	x0 = n0->x;
	x1 = n1->x;
	if (y0 > y1)
	{
		swapd(&x0, &x1);
		swapd(&y0, &y1);
	}
	x = x0;
	y = y0;
	while (y <= y1)
	{
		mlx_pixel_put(g_my->mlx, g_my->win, x, y, n0->color);
		y++;
		x = x0 + (y - y0) * (x1 - x0) / (y1 - y0);
	}
}

void			put_point(t_node *n0, t_node *n1)
{
	double y0;
	double y1;

	y0 = n0->y - n0->z;
	y1 = n1->y - n1->z;
	if (fabs(n1->x - n0->x) > fabs(y1 - y0))
		print_x(n0, n1, 0, 0);
	else
		print_y(n0, n1, 0, 0);
}

void			draw(t_node ***nd, t_fdf *my)
{
	int a;
	int b;
	int col;

	a = 0;
	col = 0x0000FF;
	g_my = my;
	while (a < nd[0][0]->h)
	{
		b = 0;
		while (b < nd[0][0]->l)
		{
			if (b != nd[0][0]->l - 1)
				put_point(nd[a][b], nd[a][b + 1]);
			if (a != nd[0][0]->h - 1)
				put_point(nd[a][b], nd[a + 1][b]);
			b++;
		}
		a++;
	}
}
