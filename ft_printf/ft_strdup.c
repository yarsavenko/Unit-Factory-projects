/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:20:16 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/27 14:17:48 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*ret_str;
	size_t	s_length;
	int		a;

	a = 0;
	s_length = ft_strlen(s);
	if (!s_length)
		ret_str = ft_strnew(1);
	else
	{
		ret_str = ft_strnew(s_length);
		if (ret_str)
			while (s[a])
			{
				ret_str[a] = s[a];
				a++;
			}
	}
	return (ret_str);
}
