/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:43:11 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/15 12:00:30 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		home_pos_detect(t_data **data)
{
	int a;
	int x;
	int y;

	a = 0;
	x = 0;
	y = 0;
	while ((*data)->map[a])
	{
		if (x == (*data)->home_side && (*data)->map[a] == (*data)->pl)
			(*data)->h_s_get = 1;
		if (x == (*data)->enemy_side && (*data)->map[a] == (*data)->pl)
			(*data)->e_s_get = 1;
		if (y == 0 && (*data)->map[a] == (*data)->pl)
			(*data)->get_top = 1;
		if (y == (*data)->y - 1 && (*data)->map[a] == (*data)->pl)
			(*data)->get_bot = 1;
		x++;
		if ((*data)->map[a] == '\n')
		{
			x = 0;
			y++;
		}
		a++;
	}
}

void		take_map(char *line, t_data **data)
{
	int		x;
	char	*map;

	line = NULL;
	x = 0;
	map = "";
	get_next_line(0, &line);
	while (x < (*data)->y)
	{
		get_next_line(0, &line);
		map = ft_strjoin(map, &(line[4]));
		map = ft_strjoin(map, "\n");
		x++;
	}
	(*data)->map = map;
	home_pos_detect(&(*data));
}
