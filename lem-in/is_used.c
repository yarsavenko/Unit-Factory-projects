/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:40:10 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/17 19:35:23 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_used(t_field **field, t_link *l)
{
	int		a;
	char	*st;
	char	*fn;
	t_path	*path;

	st = (*field)->start->name;
	fn = (*field)->end->name;
	path = (*field)->pp;
	while (path)
	{
		a = 0;
		if (path->count == 2 && (ft_strcmp(l->r1, st) || ft_strcmp(l->r2, st))
			&& (ft_strcmp(l->r1, fn) || ft_strcmp(l->r2, fn)))
			return (0);
		while (a < path->count)
		{
			if (!ft_strcmp(path->path[a], st) && !ft_strcmp(path->path[a], fn)
		&& (ft_strcmp(path->path[a], l->r1) || ft_strcmp(path->path[a], l->r2)))
				return (0);
			a++;
		}
		path = path->next;
	}
	return (1);
}
