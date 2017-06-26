/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:04:44 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/28 15:31:51 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	char	*mass;

	a = 0;
	if (s)
	{
		while (s[a])
			a++;
		mass = (char *)malloc(sizeof(char) * (a + 1));
		if (mass == 0)
			return (NULL);
		a = 0;
		while (s[a])
		{
			mass[a] = f(a, s[a]);
			a++;
		}
		mass[a] = '\0';
		return (mass);
	}
	return (NULL);
}
