/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:26:04 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/18 18:17:34 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	pr_ant(int b, char *str)
{
	ft_putstr("L");
	ft_putnbr(b);
	ft_putstr("-");
	ft_putstr(str);
}

int		make_step(t_field **field, int a)
{
	t_ant	*ant;
	t_path	*path;

	ant = (*field)->aa;
	while (ant)
	{
		path = (*field)->pp;
		if (ant->n_ant)
		{
			while (path && path->number != ant->path_n)
				path = path->next;
			pr_ant(ant->n_ant, path->path[ant->to_go]);
			if (ant->next)
				ft_putstr(" ");
			if (ft_strcmp((*field)->end->name, path->path[ant->to_go]))
			{
				ant->n_ant = 0;
				a++;
			}
			else
				ant->to_go++;
		}
		ant = ant->next;
	}
	return (a);
}

void	add_ant(t_field **field, int number, int a)
{
	t_ant *ant;

	ant = malloc(sizeof(t_ant));
	ant->path_n = number;
	ant->to_go = 1;
	ant->n_ant = (*field)->ants - a + 1;
	ant->next = NULL;
	if ((*field)->ants == a)
	{
		(*field)->aa = ant;
		(*field)->ant = ant;
	}
	else
	{
		(*field)->ant->next = ant;
		(*field)->ant = (*field)->ant->next;
	}
}

void	move_ant(t_field **field, int ant_get, int a)
{
	t_path	*path;

	while (a || ant_get != (*field)->ants)
	{
		path = (*field)->pp;
		while (path && a)
		{
			if (is_actual(field, (*field)->pp->count - 1, path, a))
			{
				add_ant(&(*field), path->number, a);
				a--;
			}
			path = path->next;
		}
		ant_get += make_step(field, 0);
		ft_putstr("\n");
	}
}
