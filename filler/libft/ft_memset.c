/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:18:32 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:18:33 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int ch, size_t num)
{
	unsigned char	*byte_mem;
	size_t			i;

	byte_mem = (unsigned char *)memptr;
	i = -1;
	while (++i < num)
		byte_mem[i] = (char)ch;
	return (byte_mem);
}
