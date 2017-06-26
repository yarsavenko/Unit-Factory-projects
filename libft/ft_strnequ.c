/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:55:44 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/30 15:38:02 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while ((*s1 || *s2) && n--)
			if (*s1++ != *s2++)
				if (*(unsigned char *)(--s1) - *(unsigned char *)(--s2))
					return (0);
		return (1);
	}
	return (0);
}
