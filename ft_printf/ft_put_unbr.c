/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:08:42 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/06 18:21:44 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_unbr(unsigned int n)
{
	int				a;
	unsigned int	b;
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
	str = ft_strnew(a--);
	str[0] = 48;
	while (n != 0)
	{
		str[a] = n % 10 + 48;
		n = n / 10;
		a--;
	}
	return (str);
}
