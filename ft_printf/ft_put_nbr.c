/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:08:42 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:17:07 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_nbr(int n)
{
	int				a;
	int				b;
	char			*str;

	a = 0;
	b = n;
	if (b == 0)
		a++;
	while (b != 0 && (a = a + 1))
		b = b / 10;
	b = 1;
	if (n < 0)
		a++;
	str = ft_strnew(a--);
	str[0] = '0';
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
