/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:20:33 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:20:43 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (!size || len_dst >= size - 1)
		return (size + len_src);
	dst += len_dst;
	ft_strncat(dst, src, size - len_dst - 1);
	return (len_dst + len_src);
}
