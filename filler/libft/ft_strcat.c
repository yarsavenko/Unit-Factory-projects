/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:18:49 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:18:49 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *source)
{
	char *ptr_dest;

	ptr_dest = destination;
	while (*destination)
		destination++;
	while (*source)
		*(destination++) = *(source++);
	*destination = 0;
	return (ptr_dest);
}
