/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:36:18 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/28 15:40:33 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		a;
	char	*mass;

	a = 0;
	if (s)
	{
		mass = (char *)malloc(sizeof(char) * (len + 1));
		if (mass == 0)
			return (NULL);
		while (len > 0)
		{
			mass[a] = s[start];
			a++;
			start++;
			len--;
		}
		mass[a] = '\0';
		return (mass);
	}
	return (NULL);
}
