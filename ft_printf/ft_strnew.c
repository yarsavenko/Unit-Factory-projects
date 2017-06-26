/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:49:44 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/24 18:33:21 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	b;

	b = 0;
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (a == 0)
		return (NULL);
	a[size] = '\0';
	while (b < size)
	{
		a[b] = '\0';
		b++;
	}
	return (a);
}
