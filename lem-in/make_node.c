/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:40:10 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/18 18:54:03 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		c_names(t_field **field, char *n1, char *n2)
{
	t_link *l;

	l = (*field)->ll;
	while (l)
	{
		if (ft_strcmp(n1, l->r1) && ft_strcmp(n2, l->r2))
			return (1);
		if (ft_strcmp(n2, l->r1) && ft_strcmp(n1, l->r2))
			return (1);
		l = l->next;
	}
	return (0);
}

void	fill_node(t_node **node, t_field **m_field)
{
	int		a;
	t_room	*r;

	r = (*m_field)->rr;
	a = 0;
	while (a < (*m_field)->count)
	{
		(*node)[a].name = (*m_field)->rooms->name;
		(*node)[a].q = 0;
		(*node)[a].l = 10000;
		(*node)[a].post = 0;
		r = r->next;
		a++;
	}
	(*m_field)->rooms = (*m_field)->rooms->next;
}

void	init_node(int a, t_node *node, t_room *r)
{
	int b;

	b = 0;
	while (b < a)
	{
		node[b].name = r->name;
		node[b].q = 0;
		node[b].l = 10000;
		node[b].post = 0;
		r = r->next;
		b++;
	}
}

void	make_node(t_field **m_field, int b)
{
	t_node	*node;
	int		d;

	node = (t_node *)malloc(sizeof(t_node) * (*m_field)->count);
	init_node((*m_field)->count, node, (*m_field)->rr);
	(*m_field)->node = node;
	d = 1;
	while (d)
	{
		b = 0;
		while (b < (*m_field)->count)
		{
			node[b].q = 0;
			node[b].l = 10000;
			node[b].post = 0;
			b++;
		}
		(*m_field)->node = node;
		find_path(&(*m_field));
		d = take_path(&(*m_field), &node, 0, 0);
	}
	if ((*m_field)->pp && (*m_field)->ants > 0)
		move_ant(m_field, 0, (*m_field)->ants);
	else
		ft_putstr("ERROR\n");
}
