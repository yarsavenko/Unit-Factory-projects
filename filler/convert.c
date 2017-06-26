/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 13:48:48 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 13:57:31 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	make_int(int ***mapi, t_data **data)
{
	int a;
	int b;
	int c;

	b = 0;
	c = 0;
	(*mapi) = (int **)malloc(sizeof(int *) * (*data)->h);
	while (b < (*data)->h)
	{
		a = 0;
		(*mapi)[b] = (int *)malloc(sizeof(int) * (*data)->l);
		while (a < (*data)->l)
			(*mapi)[b][a++] = (*data)->fig[c++];
		c++;
		b++;
	}
}

void	convert(t_data **data)
{
	int a;
	int b;
	int c;
	int **mass;
	int **mapi;

	b = 0;
	c = 0;
	(*data)->pos_count = 0;
	(*data)->pos_pos = NULL;
	(*data)->pos_pos = (int **)malloc(sizeof(int *) * 1000);
	mass = (int **)malloc(sizeof(int *) * (*data)->y);
	while (b < (*data)->y)
	{
		a = 0;
		mass[b] = (int *)malloc(sizeof(int) * (*data)->x);
		while (a < (*data)->x)
			mass[b][a++] = (*data)->map[c++];
		c++;
		b++;
	}
	make_int(&mapi, &(*data));
	puter(&(*data), mass, mapi);
}
