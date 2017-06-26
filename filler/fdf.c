/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:59:04 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:06:52 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			find_xy(t_node ***asd, int *x, int *y)
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

t_fdf			*init_fdf(t_node ***asd, t_fdf **my)
{
	if (!(*my))
	{
		(*my) = (t_fdf *)malloc(sizeof(t_fdf));
		find_xy(asd, &(*my)->x, &(*my)->y);
		(*my)->mlx = mlx_init();
		(*my)->win = mlx_new_window((*my)->mlx, (*my)->x, (*my)->y, "fdf");
	}
	mlx_clear_window((*my)->mlx, (*my)->win);
	(*my)->shag = 20;
	(*my)->angle = 45;
	(*my)->asd = asd;
	(*my)->xangle = 45;
	(*my)->m = 1;
	(*my)->fm = 0;
	return ((*my));
}

void			make_pic(t_data **data, char **line, t_fdf **my)
{
	t_node	***asdq;

	asdq = make_map((*data)->map, 0, (*data)->x, (*data)->y);
	if (asdq)
	{
		init_fdf(asdq, &(*my));
		find_center(asdq, (*my), 1);
		swap(asdq);
		draw(asdq, (*my));
		(*my)->data = (*data);
		(*my)->qqq = (*line);
		mlx_key_hook((*my)->win, keycode, (*my));
		mlx_loop((*my)->mlx);
	}
	else
		printf("invalid map");
}
