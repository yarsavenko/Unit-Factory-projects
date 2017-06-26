/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:00:51 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/20 13:19:41 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

long	atolo(char *str)
{
	long	nbr;
	int		a;
	int		b;
	int		d;

	a = 0;
	b = 1;
	d = 0;
	nbr = 0;
	while (str[a] <= 32)
		a++;
	if (str[a] == '+')
		a++;
	if (str[a] == '-' || !(str[a] >= 48 && str[a] <= 57))
		return (-1);
	while (str[a] && (str[a] >= 48 || str[a] <= 57))
	{
		nbr = (str[a] + 48) * b + nbr;
		a++;
		d++;
	}
	if (d > 10)
		return (-1);
	return (nbr);
}

int		is_int(char *str, int c)
{
	int		a;
	long	b;

	a = ft_strlen(str) - c;
	if (a > 10)
		return (0);
	b = atolo(str);
	if (b > 0 && b <= 2147483646)
		return (1);
	return (0);
}

int		is_validroom(char *str)
{
	int a;
	int count;

	a = 0;
	count = 1;
	while (str[a])
	{
		if (str[a] == ' ' && str[a + 1])
			count++;
		if (str[a] == '-')
			return (0);
		a++;
	}
	if (count != 3 || str[0] == 'L' || str[0] == '#')
		return (0);
	return (1);
}

char	*take_name(char *str, int *b, char c)
{
	int		a;
	char	*name;

	a = 0;
	while (str[a] && str[a] != c)
		a++;
	name = (char *)malloc(sizeof(char) * (a + 1));
	name[a] = '\0';
	a = 0;
	while (str[a] && str[a] != c)
	{
		name[a] = str[a];
		a++;
	}
	*b = a + 1 + *b;
	return (name);
}

int		take_room(char *str, char c, t_field **m_field)
{
	int		a;
	t_room	*room;

	if (!is_validroom(str) || (*m_field)->ants == -1 || (*m_field)->count_l)
		return (0);
	room = (t_room*)malloc(sizeof(t_room));
	a = 0;
	room->name = take_name(str, &a, ' ');
	room->x = (int)atolo(&str[a]);
	if (room->x < 0 || !dop_valid((*m_field), room->name))
	{
		free(room->name);
		free(room);
		return (0);
	}
	a++;
	room->y = (int)atolo(&str[++a]);
	if (room->y < 0)
	{
		free(room->name);
		free(room);
		return (0);
	}
	fill_rooms(room, &(*m_field), c);
	return (1);
}
