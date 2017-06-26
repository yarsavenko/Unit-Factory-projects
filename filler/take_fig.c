/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:08:33 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 13:02:26 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	take_fig(char *line, t_data **data)
{
	int		h;
	int		l;
	char	**str;
	int		a;
	char	*fig;

	(*data)->count++;
	a = 0;
	fig = "";
	str = ft_strsplit(line, ' ');
	h = ft_atoi(str[1]);
	l = ft_atoi(str[2]);
	while (a < h)
	{
		get_next_line(0, &line);
		fig = ft_strjoin(fig, line);
		fig = ft_strjoin(fig, "\n");
		a++;
	}
	(*data)->fig = fig;
	(*data)->l = l;
	(*data)->h = h;
}
