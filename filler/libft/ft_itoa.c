/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:08:41 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/30 16:23:36 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*etur;
	int		c;

	c = ft_count_digits(n);
	etur = (char *)malloc(sizeof(*etur) * (c + 1));
	if (etur == 0)
		return (NULL);
	etur[c] = '\0';
	if (n == 0 || n == -0)
		etur[0] = 48;
	if (n < 0)
		etur[0] = '-';
	while (c-- > 1)
	{
		if (n % 10 < 0)
			etur[c] = -1 * (n % 10) + 48;
		else
			etur[c] = n % 10 + 48;
		n = n / 10;
	}
	if (n < 10 && n > 0)
		etur[c] = n + 48;
	return (etur);
}
