/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:25:00 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/28 15:47:18 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int a;

	if (s)
	{
		a = 0;
		while (s[a])
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
	}
}
