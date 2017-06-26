/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:21:13 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:21:13 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *ptr_dst;

	ptr_dst = dst;
	while (len > 0 && *src != '\0')
	{
		*ptr_dst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*ptr_dst++ = '\0';
		len--;
	}
	return (dst);
}
