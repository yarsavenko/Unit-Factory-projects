/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_razm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:20:07 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/12 15:32:54 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		find_razm(char *line, t_data **data)
{
	char **lines;

	lines = ft_strsplit(line, ' ');
	(*data)->x = ft_atoi(lines[2]);
	(*data)->y = ft_atoi(lines[1]);
}
