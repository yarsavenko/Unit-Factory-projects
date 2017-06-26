/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 08:48:17 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 09:35:03 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int		take_color(char *str, unsigned int *col)
{
	int				a;
	unsigned int	b;

	a = 0;
	b = 0;
	if (str[a] == ',')
		a++;
	if (str[a] == '0')
		a++;
	if (str[a] == 'x')
		a++;
	while ((str[a] >= 0 && str[a] <= 9) || (str[a] >= 'A' && str[a] <= 'F') ||
			(str[a] >= 'a' && str[a] <= 'f'))
	{
		if (str[a] >= 0 && str[a] <= 9)
			b = b * 16 + (str[a] - 48);
		if (str[a] >= 'A' && str[a] <= 'F')
			b = b * 16 + (str[a] - 'A' + 10);
		if (str[a] >= 'a' && str[a] <= 'f')
			b = b * 16 + (str[a] - 'a' + 10);
		a++;
	}
	*col = b;
	return (a);
}
