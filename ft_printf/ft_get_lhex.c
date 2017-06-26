/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:49:43 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:14:31 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_d(unsigned long nb, int base)
{
	int a;

	a = 0;
	if (nb == 0)
		a++;
	while (nb != 0)
	{
		a++;
		nb = nb / base;
	}
	return (a);
}

char		*ft_get_lhex(unsigned long nb, char c, int base)
{
	unsigned long	a;
	char			*ret;
	int				count;

	if (c == 88)
		c = 0;
	else
		c = 32;
	a = nb;
	count = count_d(nb, base);
	ret = (char *)malloc(sizeof(char) * (count + 1));
	ret[count--] = '\0';
	ret[0] = 48;
	while (a != 0)
	{
		nb = a % base;
		if (nb > 9)
			nb = nb + 7 + c;
		ret[count] = nb + 48;
		a = a / base;
		count--;
	}
	return (ret);
}
