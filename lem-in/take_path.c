/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:40:10 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/17 19:14:09 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*take_hname(char *fn, t_node *node, int a)
{
	int b;

	b = 0;
	while (b < a)
	{
		if (ft_strcmp(node[b].name, fn))
			return (node[b].q);
		b++;
	}
	return (0);
}

void	add_path(t_field **field, char **path, int count)
{
	int		a;
	t_path	*p;

	a = 0;
	p = malloc(sizeof(t_path));
	p->path = path;
	p->count = count;
	p->step_left = count - 1;
	p->ant_n = 0;
	(*field)->count_path++;
	p->number = (*field)->count_path;
	p->next = NULL;
	if ((*field)->count_path == 1)
	{
		(*field)->path = p;
		(*field)->pp = p;
	}
	else
	{
		(*field)->path->next = p;
		(*field)->path = (*field)->path->next;
	}
}

int		take_path(t_field **field, t_node **node, int b, int a)
{
	char	*fn;
	int		hop;
	char	**path;
	int		cf;

	fn = (*field)->end->name;
	a = (*field)->count;
	while (b < a)
	{
		if (ft_strcmp((*node)[b].name, fn))
			hop = (*node)[b].l;
		b++;
	}
	if (hop == 10000)
		return (0);
	path = (char **)malloc(sizeof(char *) * (hop + 1));
	cf = hop + 1;
	while (hop >= 0)
	{
		path[hop] = fn;
		fn = take_hname(fn, (*node), a);
		hop--;
	}
	add_path(&(*field), path, cf);
	return (1);
}
