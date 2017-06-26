/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:40:31 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:19:39 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_ulnbr(unsigned long n)
{
	int				a;
	unsigned long	b;
	char			*str;

	a = 0;
	b = n;
	if (b == 0)
		a++;
	while (b != 0)
	{
		a++;
		b = b / 10;
	}
	b = 1;
	str = ft_strnew(a--);
	str[0] = 48;
	while (n != 0)
	{
		str[a] = b * n % 10 + 48;
		n = n / 10;
		a--;
	}
	return (str);
}
