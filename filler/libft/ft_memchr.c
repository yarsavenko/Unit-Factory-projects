/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:16:52 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:16:53 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	size_t	i;

	i = -1;
	while (++i < num)
		if (((unsigned char*)memptr)[i] == (unsigned char)val)
			return (void *)((size_t)(memptr + i));
	return (0);
}
