/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:03:19 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/30 18:38:40 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_trim(char const *s)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	b = ft_strlen(s);
	while (s[b - 1] <= 32)
		b--;
	while (s[a] <= 32)
		a++;
	c = b - a;
	if (c < 0)
		c = 0;
	return (c);
}

char			*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		d;
	char	*mass;

	a = 0;
	if (s)
	{
		b = count_trim(s);
		mass = (char *)malloc(sizeof(char) * (b + 1));
		if (mass == 0)
			return (NULL);
		d = 0;
		while (s[a] <= 32)
			a++;
		while (b-- > 0)
		{
			mass[d] = s[a];
			d++;
			a++;
		}
		mass[d] = '\0';
		return (mass);
	}
	return (NULL);
}
