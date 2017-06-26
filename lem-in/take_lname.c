/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_lname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:12:53 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/18 17:12:54 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*take_lname(int count, char *str, int *a)
{
	int		b;
	int		c;
	char	*name;

	c = 0;
	b = 0;
	while (str[b] && c != count)
	{
		if (str[b] == '-')
			c++;
		b++;
	}
	name = malloc(sizeof(char) * b);
	name[b] = '\0';
	(*a) = b;
	b--;
	c = 0;
	while (c < b)
	{
		name[c] = str[c];
		c++;
	}
	return (name);
}
