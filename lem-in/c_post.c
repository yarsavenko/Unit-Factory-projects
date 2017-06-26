/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_post.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:55:49 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/20 18:42:42 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		c_post(t_node *node, int a, char *name)
{
	int b;

	b = 0;
	while (b < a)
	{
		if (ft_strcmp(node[b].name, name) && node[b].post == 0)
			return (b);
		b++;
	}
	return (0);
}

int		dop_valid(t_field *field, char *str)
{
	t_room *room;

	room = field->rr;
	while (room)
	{
		if (ft_strcmp(str, room->name))
			return (0);
		room = room->next;
	}
	return (1);
}

int		l_c(char *name, char *name2, t_field *field)
{
	t_link *link;

	link = field->ll;
	while (link)
	{
		if ((ft_strcmp(name, link->r1) || ft_strcmp(name, link->r2))
			&& (ft_strcmp(name2, link->r1) || ft_strcmp(name2, link->r2)))
			return (1);
		link = link->next;
	}
	return (0);
}

int		count_b(char *str)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == '-' && a != 0)
			b++;
		a++;
	}
	return (b);
}
