/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:18:14 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:18:15 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t count)
{
	size_t i;

	i = 0;
	if (destination > source)
	{
		while (source - 1 != source + count - 1 - i)
		{
			*(unsigned char *)(destination + count - 1 - i) =
				*(unsigned char *)(source + count - 1 - i);
			i++;
		}
	}
	else
		ft_memcpy(destination, source, count);
	return (destination);
}
