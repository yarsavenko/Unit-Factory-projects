/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 13:01:12 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:07:45 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_data(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	(*data)->enemy[1] = 0;
	(*data)->enemy[0] = 0;
	(*data)->pl_n = 0;
	(*data)->e_s_get = 0;
	(*data)->h_s_get = 0;
	(*data)->count = 0;
	(*data)->pos_pos = (int **)malloc(sizeof(int *) * 1000);
	(*data)->pos_count = 0;
}

void	if_piece(t_data **data, char *line)
{
	char	*map;
	char	*nnn;

	take_fig(line, &(*data));
	convert(&(*data));
	map = ft_itoa((*data)->yret);
	nnn = ft_itoa((*data)->xret);
	map = ft_strjoin(map, " ");
	map = ft_strjoin(map, nnn);
	map = ft_strjoin(map, "\n");
	ft_putstr_fd(map, 1);
	map = NULL;
	nnn = NULL;
}

void	init_pl(t_data **data, char *line)
{
	(*data)->pl = 'X';
	(*data)->enem = 'O';
	(*data)->pl_n = line[10] - 48;
	if ((*data)->pl_n == 1)
	{
		(*data)->pl = 'O';
		(*data)->enem = 'X';
	}
}

void	inner_fil(char **line, t_data **data, t_fdf *my)
{
	while (get_next_line(0, &(*line)) > 0)
	{
		if (str_filler((*line), "$$$") && str_filler((*line), "filler"))
			init_pl(&(*data), (*line));
		if (str_filler((*line), "Plateau"))
		{
			find_razm((*line), &(*data));
			take_map((*line), &(*data));
			if ((*data)->enemy[0] == 0 && (*data)->enemy[1] == 0)
				find_enemy(&(*data));
		}
		if (str_filler((*line), "Piece"))
		{
			if_piece(&(*data), (*line));
			if ((*data)->x < 20)
				make_pic(&(*data), &(*line), &my);
		}
	}
}

int		main(void)
{
	char	*line;
	t_data	*data;
	t_fdf	*my;

	init_data(&data);
	inner_fil(&line, &data, my);
	return (0);
}
