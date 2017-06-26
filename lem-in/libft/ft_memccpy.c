/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:52:23 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:52:25 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((char *)dest)[i] = ((char*)source)[i];
		if (((char *)(dest))[i] == (char)ch)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
