/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:53:51 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:53:52 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	char	*ptr_des;
	size_t	i;

	ptr_des = destination;
	while (*ptr_des)
		ptr_des++;
	i = -1;
	while (++i < num && *source)
		*(ptr_des++) = *(source++);
	*ptr_des = 0;
	return (destination);
}
