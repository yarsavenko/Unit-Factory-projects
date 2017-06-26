/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_actual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:35:42 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/18 16:52:46 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_actual(t_field **field, int fastest, t_path *cur, int a_left)
{
	t_path	*path;
	int		a;
	int		c;

	path = (*field)->pp;
	a = 0;
	c = 0;
	if (cur->count - 1 == fastest)
		return (1);
	while (path)
	{
		if (path->count >= cur->count)
			break ;
		if (path->ant_n)
			a += path->step_left;
		a += a_left * (path->count - 1);
		path = path->next;
		c++;
	}
	if (c != 0)
		c = a / c;
	if (c >= cur->count - 1)
		return (1);
	return (0);
}
