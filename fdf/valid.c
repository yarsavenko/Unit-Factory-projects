/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:18:01 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 15:37:15 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid(char *str, int c, int b)
{
	int h;
	int l;
	int a;

	h = -1;
	a = 0;
	while (++h < c && str[a])
	{
		l = 0;
		while (str[a] != '\n')
		{
			while (str[a] <= 32 && str[a] != '\n')
				a++;
			if (str[a] > 32)
			{
				while (str[a] > 32)
					a++;
				l++;
			}
		}
		if (b != l)
			return (0);
		a++;
	}
	return (1);
}
