/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:59:04 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 15:39:14 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		find_xy(t_node ***asd, int *x, int *y)
{
	*x = asd[0][0]->l * 40;
	*y = asd[0][0]->h * 40;
	if (*x < 400)
		*x = 400;
	if (*x > 2400)
		*x = 2400;
	if (*y < 400)
		*y = 400;
	if (*y > 1600)
		*y = 1600;
}

t_fdf		*init_fdf(t_node ***asd)
{
	t_fdf *my;

	my = (t_fdf *)malloc(sizeof(t_fdf));
	my->mlx = mlx_init();
	find_xy(asd, &my->x, &my->y);
	my->win = mlx_new_window(my->mlx, my->x, my->y, "fdf");
	my->shag = 20;
	my->angle = 45;
	my->asd = asd;
	my->xangle = 45;
	my->m = 1;
	my->fm = 0;
	return (my);
}

int			main(int argc, char **argv)
{
	t_fdf	*my;
	t_node	***asdq;

	if (argc > 1)
	{
		asdq = make_map(argv[1], 0, 0, 0);
		if (asdq)
		{
			my = init_fdf(asdq);
			find_center(asdq, my, 1);
			swap(asdq);
			draw(asdq, my);
			mlx_key_hook(my->win, keycode, my);
			mlx_loop(my->mlx);
		}
		else
			printf("invalid map");
	}
	else
		printf("enter file name");
}
