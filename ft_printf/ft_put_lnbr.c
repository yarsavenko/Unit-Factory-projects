/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:57:48 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 17:03:01 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(long n)
{
	int a;

	a = 0;
	if (n == 0)
		a++;
	if (n < 0)
		a++;
	while (n != 0)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

char		*ft_put_lnbr(long n)
{
	int		a;
	int		b;
	char	*str;

	b = 1;
	if (n < 0)
		b = -1;
	a = count(n);
	str = ft_strnew(a--);
	str[0] = 48;
	if (n < 0 && (b = -1))
		str[0] = '-';
	while (n != 0)
	{
		str[a] = b * (n % 10) + 48;
		n = n / 10;
		a--;
	}
	return (str);
}
