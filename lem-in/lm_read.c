/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:43:09 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/20 18:56:52 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_ants(char *str, t_field **field)
{
	int		a;
	int		b;
	char	*c;

	b = 0;
	c = ft_strtrim(str);
	a = ft_strlen(c);
	while (c[b] && c[b] >= 48 && c[b] <= 57)
		b++;
	if (a == b && is_int(c, 0))
	{
		(*field)->ants = ft_atoi(c);
		free(c);
		return (1);
	}
	else
	{
		free(c);
		return (chek_str(str, &(*field)));
	}
}

void	printt(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}

int		ampers(t_field **m_f, int fd, char *line, int b)
{
	char	buff;
	char	*nline;

	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") || ft_strcmp(line, "##end"))
		{
			buff = line[2];
			if ((buff == 's' && (*m_f)->start) || (buff == 'e' && (*m_f)->end))
				return (0);
			if (get_next_line(fd, &nline) > 0)
			{
				printt(nline);
				b = take_room(nline, buff, &(*m_f));
				free(nline);
			}
			else
				return (0);
		}
	}
	return (b);
}

void	fill_it(t_field **m_field, char *str, int b)
{
	int		fd;
	char	*line;
	int		fff;

	fd = open(str, O_RDONLY);
	fd = 0;
	line = NULL;
	b = 1;
	while (b > 0 && (fff = get_next_line(fd, &line) > 0) && ft_strlen(line))
	{
		ft_putstr(line);
		ft_putstr("\n");
		if (line[0] == '#')
			b = ampers(&(*m_field), fd, line, 1);
		else if ((*m_field)->ants == -1)
			b = is_ants(line, &(*m_field));
		else
			b = chek_str(line, &(*m_field));
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
}

void	lem_read(char *str, t_field **m_field)
{
	fill_it(&(*m_field), str, 1);
	if ((*m_field)->start && (*m_field)->end && (*m_field)->ants >= 0)
		make_node(&(*m_field), 0);
	else
		ft_putstr("ERROR\n");
}
