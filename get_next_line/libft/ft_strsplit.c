/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:50:29 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/30 18:36:11 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		fullbuff(char *buff, char const *s, int a, char c)
{
	int b;

	b = 0;
	while (s[a] != c && s[a])
	{
		buff[b] = s[a];
		a++;
		b++;
	}
	buff[b] = '\0';
	return (a);
}

static void		fullmass(char **mass, char const *s, char c)
{
	int		a;
	int		b;
	int		d;

	b = 0;
	a = 0;
	while (s[a] == c)
		a++;
	while (s[a])
	{
		d = ft_count_chr(s, a, c);
		mass[b] = (char *)malloc(sizeof(char) * (d + 1));
		a = fullbuff(mass[b], s, a, c);
		while (s[a] == c)
			a++;
		b++;
	}
	mass[b] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mass;
	int		b;

	if (s)
	{
		b = ft_count_word(s, c);
		mass = (char**)malloc(sizeof(char*) * (b + 1));
		if (mass == 0)
			return (NULL);
		fullmass(mass, s, c);
		return (mass);
	}
	return (NULL);
}
