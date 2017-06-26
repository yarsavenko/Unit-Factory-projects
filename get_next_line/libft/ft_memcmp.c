/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:17:14 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:17:15 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cptr_s1;
	unsigned char	*cptr_s2;

	i = -1;
	cptr_s1 = (unsigned char *)s1;
	cptr_s2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (cptr_s1[i] != cptr_s2[i])
			return (cptr_s1[i] - cptr_s2[i]);
	}
	return (0);
}
