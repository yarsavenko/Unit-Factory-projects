/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:21:24 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:21:25 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char *ret_big;

	ret_big = ft_strstr(big, little);
	if ((ret_big - big) + ft_strlen(little) > len)
		return (0);
	return (ret_big);
}
