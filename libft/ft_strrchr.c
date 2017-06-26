/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:21:35 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:21:36 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char *cur_pos;

	cur_pos = 0;
	while (*s)
	{
		if (*s == (char)ch)
			cur_pos = (char *)((size_t)s);
		s++;
	}
	if (!ch)
		return ((char*)((size_t)s));
	return (cur_pos);
}
