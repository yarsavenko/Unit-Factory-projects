/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:54:19 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/18 16:54:22 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		find_post(t_node **node, int a)
{
	int b;
	int post;
	int l;

	l = 10000;
	post = -1;
	b = 0;
	while (b < a)
	{
		if ((*node)[b].post == 0 && (*node)[b].l < l)
		{
			l = (*node)[b].l;
			post = b;
		}
		b++;
	}
	(*node)[post].post = 1;
	return (post);
}

void	if_i(int i, t_node **node, int p)
{
	int buff;

	if ((*node)[i].l == 10000)
	{
		(*node)[i].l = 1 + (*node)[p].l;
		(*node)[i].q = (*node)[p].name;
	}
	else
	{
		buff = (*node)[i].l + (*node)[p].l;
		if (buff < (*node)[i].l)
		{
			(*node)[i].l = buff;
			(*node)[i].q = (*node)[p].name;
		}
	}
}

void	while_l(int a, t_node **node, int p, t_field **field)
{
	t_link	*l;
	int		i;

	l = (*field)->ll;
	while (l)
	{
		if (is_used(field, l))
		{
			if (ft_strcmp((*node)[p].name, l->r1))
			{
				i = c_post((*node), a, l->r2);
				if (i)
					if_i(i, &(*node), p);
			}
			else if (ft_strcmp((*node)[p].name, l->r2))
			{
				i = c_post((*node), a, l->r1);
				if (i)
					if_i(i, &(*node), p);
			}
		}
		l = l->next;
	}
}

void	find_one(t_field **field, t_node **node, int p, int a)
{
	while (1)
	{
		while_l(a, &(*node), p, field);
		p = find_post(&(*node), a);
		if (p == -1 || ft_strcmp((*field)->end->name, (*node)[p].name))
			break ;
	}
}

int		find_path(t_field **field)
{
	int		i;
	t_node	*node;
	int		p;

	node = (*field)->node;
	i = 0;
	p = 0;
	while (i < (*field)->count)
	{
		if (ft_strcmp((*field)->start->name, node[i].name))
		{
			node[i].l = 0;
			node[i].post = 1;
			p = i;
		}
		if (ft_strcmp((*field)->end->name, node[i].name))
		{
			node[i].post = 0;
		}
		i++;
	}
	find_one(field, &node, p, (*field)->count);
	return (1);
}
