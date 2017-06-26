/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:00:24 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 14:42:45 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_more_optimal(int *x, int *y, t_data *data)
{
	double	a;
	int		c;
	double	b;
	int		d;

	d = data->enemy_side;
	if (data->e_s_get)
		d = data->home_side;
	c = 1;
	(*x) = data->pos_pos[0][0];
	(*y) = data->pos_pos[0][1];
	while (c < data->pos_count)
	{
		a = abs(data->pos_pos[c][0] - d);
		b = abs((*x) - d);
		if (a < b)
		{
			(*x) = data->pos_pos[c][0];
			(*y) = data->pos_pos[c][1];
		}
		c++;
	}
}

void	if_c(int *f, int *r, int c, t_data *data)
{
	if (c == 10)
	{
		(*f) = data->x - 1;
		(*r) = 5;
	}
	if (c == 11)
	{
		(*f) = 0;
		(*r) = 0;
	}
}

void	if_cc(int *f, int *r, int c, t_data *data)
{
	if (data->x > 20 && data->x < 80 && data->pl == 'X' && !data->e_s_get)
	{
		(*f) = 0;
		(*r) = data->enemy[1] + 9;
		if (data->e_s_get)
		{
			(*f) = 0;
			(*r) = 0;
		}
	}
	else if (data->x >= 80 && data->pl == 'O')
	{
		(*f) = 0;
		(*r) = data->enemy[1] + 9;
		if (data->e_s_get)
		{
			(*f) = data->x - 1;
			(*r) = 0;
		}
	}
}

void	get_enem(int *x, int *y, t_data *data, int c)
{
	double	a;
	double	b;
	int		f;
	int		r;

	f = data->enemy[0];
	r = data->enemy[1];
	if_c(&f, &r, c, data);
	if_cc(&f, &r, c, data);
	c = 1;
	(*x) = data->pos_pos[0][0];
	(*y) = data->pos_pos[0][1];
	while (c < data->pos_count)
	{
		a = pow(pow((data->pos_pos[c][0] - f), 2)
		+ pow((data->pos_pos[c][1] - r), 2), 0.5);
		b = pow(pow(((*x) - f), 2) + pow(((*y) - r), 2), 0.5);
		if (a < b)
		{
			(*x) = data->pos_pos[c][0];
			(*y) = data->pos_pos[c][1];
		}
		c++;
	}
	free(data->pos_pos);
}

void	find_optimal(int *x, int *y, t_data *data, int c)
{
	double	a;
	double	b;

	if (data->x < 20 && data->pl == 'X' && !data->e_s_get)
		get_enem(&(*x), &(*y), data, 11);
	else if ((data->count < 180 && (!data->e_s_get && !data->h_s_get))
		|| (data->e_s_get && data->h_s_get && data->x < 20))
		get_enem(&(*x), &(*y), data, c);
	else
		find_more_optimal(&(*x), &(*y), data);
}
