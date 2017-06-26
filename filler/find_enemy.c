/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:15:39 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 13:01:04 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		find_sides(t_data **data)
{
	if ((*data)->x - 1 - (*data)->enemy[0] > ((*data)->x - 1) / 2)
	{
		(*data)->enemy_side = 0;
		(*data)->home_side = (*data)->x - 1;
	}
	else
	{
		(*data)->enemy_side = (*data)->x - 1;
		(*data)->home_side = 0;
	}
}

void		find_enemy(t_data **data)
{
	int a;
	int x;
	int y;

	a = 0;
	x = 0;
	y = 0;
	while ((*data)->map[a])
	{
		if ((*data)->map[a] == (*data)->enem)
			break ;
		x++;
		if ((*data)->map[a] == '\n')
		{
			x = 0;
			y++;
		}
		a++;
	}
	(*data)->enemy[0] = x;
	(*data)->enemy[1] = y;
	find_sides(&(*data));
}
