/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:18:38 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/24 16:05:15 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*mass;

	if (s1 && s2)
	{
		a = ft_strlen(s1);
		b = ft_strlen(s2);
		mass = (char *)malloc(sizeof(char) * (a + b + 1));
		if (mass == 0)
			return (NULL);
		a = -1;
		b = 0;
		while (s1[++a])
			mass[a] = s1[a];
		while (s2[b])
		{
			mass[a] = s2[b];
			a++;
			b++;
		}
		mass[a] = '\0';
		return (mass);
	}
	return (NULL);
}
