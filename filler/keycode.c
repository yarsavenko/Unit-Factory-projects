/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 15:22:49 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:06:56 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	kkk(t_fdf *my)
{
	if (my->fm)
	{
		multi_z(my->asd, my->m, my->fm);
		my->fm = 0;
	}
	find_center(my->asd, my, 1);
	mlx_clear_window(my->mlx, my->win);
	draw(my->asd, my);
}

int		keycode(int keycode, t_fdf *my)
{
	my->angle -= (keycode == 123) ? 2 : 0;
	my->angle += (keycode == 124) ? 2 : 0;
	my->shag += (keycode == 24) ? 1 : 0;
	if (keycode == 27)
		my->shag -= (my->shag - 1 > 0) ? 1 : 0;
	my->x -= (keycode == 0) ? 5 : 0;
	my->x += (keycode == 2) ? 5 : 0;
	my->y -= (keycode == 13) ? 5 : 0;
	my->y += (keycode == 1) ? 5 : 0;
	my->xangle += (keycode == 126) ? 2 : 0;
	my->xangle -= (keycode == 125) ? 2 : 0;
	kkk(my);
	if (keycode == 49)
		inner_fil(&my->qqq, &my->data, my);
	if (keycode == 53)
		exit(0);
	return (1);
}
