/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:20:16 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 12:18:10 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret_str;
	size_t	s_length;

	s_length = ft_strlen(s);
	if (!s_length)
		ret_str = ft_memalloc(1);
	else
	{
		ret_str = ft_strnew(s_length);
		if (ret_str)
			ft_memcpy(ret_str, s, s_length);
	}
	return (ret_str);
}
