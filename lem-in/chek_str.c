/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:28:15 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/20 18:51:25 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		fill_rooms(t_room *room, t_field **m_field, char c)
{
	room->next = NULL;
	if ((*m_field)->count == 0)
	{
		(*m_field)->count = 1;
		(*m_field)->rooms = room;
		(*m_field)->rr = room;
	}
	else
	{
		(*m_field)->count++;
		((*m_field)->rooms)->next = room;
		(*m_field)->rooms = ((*m_field)->rooms)->next;
	}
	if (c == 's')
		(*m_field)->start = room;
	else if (c == 'e')
		(*m_field)->end = room;
}

int			check_name(t_field **m_field, char *name)
{
	t_room	*buff;

	buff = (*m_field)->rr;
	while (buff)
	{
		if (ft_strcmp(buff->name, name))
			return (1);
		buff = buff->next;
	}
	if (((*m_field)->start && ft_strcmp(name, ((*m_field)->start)->name)) ||
			((*m_field)->end && ft_strcmp(name, ((*m_field)->end)->name)))
		return (1);
	return (0);
}

void		fill_links(t_link *link, t_field **m_field)
{
	link->next = NULL;
	if ((*m_field)->count_l == 0)
	{
		(*m_field)->count_l = 1;
		(*m_field)->links = link;
		(*m_field)->ll = link;
	}
	else
	{
		(*m_field)->count_l++;
		((*m_field)->links)->next = link;
		(*m_field)->links = ((*m_field)->links)->next;
	}
}

int			take_link(char *str, t_field **m_field, int a, int b)
{
	char	*name;
	t_link	*link;
	char	*name1;

	b = count_b(str);
	a = 0;
	name = take_lname(b, str, &a);
	if (!ft_strlen(name) || (*m_field)->ants == -1 || (*m_field)->count == 0)
	{
		free(name);
		return (0);
	}
	name1 = take_name(&str[a], &a, '\0');
	if ((!(check_name(&(*m_field), name) && check_name(&(*m_field), name1)))
		|| ft_strcmp(name, name1) || l_c(name, name1, (*m_field)))
	{
		free(name);
		free(name1);
		return (0);
	}
	link = (t_link *)malloc(sizeof(t_link));
	link->r1 = name;
	link->r2 = name1;
	fill_links(link, &(*m_field));
	return (1);
}

int			chek_str(char *str, t_field **m_field)
{
	int		a;

	a = 0;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[a] && str[a] != ' ')
		a++;
	if (str[a] == ' ')
		a = take_room(str, 'r', &(*m_field));
	else
		a = take_link(str, &(*m_field), 0, 0);
	return (a);
}
