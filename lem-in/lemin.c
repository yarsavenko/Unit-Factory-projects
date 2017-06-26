/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:40:10 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/20 18:52:30 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_field		*m_field;

	argc = argc + 1 - 1;
	m_field = (t_field *)malloc(sizeof(t_field));
	m_field->ants = -1;
	m_field->count = 0;
	m_field->count_path = 0;
	m_field->count_l = 0;
	m_field->start = NULL;
	m_field->end = NULL;
	m_field->rr = NULL;
	lem_read(argv[1], &m_field);
	return (0);
}
