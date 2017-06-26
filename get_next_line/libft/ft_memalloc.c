/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:22:00 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/27 15:20:38 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	b;

	b = 0;
	a = malloc(size);
	if (a == 0)
		return (0);
	while (b < size)
	{
		a[b] = 0;
		b++;
	}
	return (a);
}
