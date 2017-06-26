/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:19:55 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:19:56 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	char *start_dest;

	start_dest = destination;
	while (*source)
		*(destination++) = *(source++);
	*(destination) = *(source);
	return (start_dest);
}
