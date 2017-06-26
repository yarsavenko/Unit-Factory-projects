/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:45:05 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/15 14:07:11 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data			**g_data;

int				chek_kontakt(int **mass, int y, int x, t_data *data)
{
	if (x < data->x && y < data->y && (mass[y][x] == data->pl))
		return (1);
	return (0);
}

int				chek_tochka(int **mass, int y, int x, char c)
{
	if (x > (*g_data)->x - 1 || y > (*g_data)->y - 1)
		return (0);
	if (c == '*' && (mass[y][x] == (*g_data)->pl ||
			mass[y][x] == (*g_data)->pl + 32 || mass[y][x] == '.'))
		return (1);
	else if (c == '.')
		return (1);
	return (0);
}

int				put_fig(int **mass, int **mapi, int y, int x)
{
	int b;
	int c;
	int flag;

	b = 0;
	flag = 0;
	while (b < (*g_data)->h)
	{
		c = 0;
		while (c < (*g_data)->l)
		{
			if (!chek_tochka(mass, y + b, x + c, mapi[b][c]))
				return (0);
			if ((mapi[b][c] == '*') && chek_kontakt(mass, y + b, x + c,
				(*g_data)))
				flag++;
			c++;
		}
		b++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void			add_pos(t_data **data, int x, int y)
{
	(*data)->pos_pos[(*data)->pos_count] = (int *)malloc(sizeof(int) * 2);
	(*data)->pos_pos[(*data)->pos_count][0] = x;
	(*data)->pos_pos[(*data)->pos_count][1] = y;
	(*data)->pos_count++;
}

void			puter(t_data **data, int **mass, int **mapi)
{
	int x;
	int y;

	x = 0;
	y = 0;
	g_data = data;
	while (y < (*data)->y)
	{
		x = 0;
		while (x < (*data)->x)
		{
			if (put_fig(mass, mapi, y, x))
				add_pos(&(*data), x, y);
			x++;
		}
		y++;
	}
	if ((*data)->pos_count >= 1)
		find_optimal(&x, &y, (*data), 0);
	(*data)->xret = x;
	(*data)->yret = y;
}
