/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:31:52 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/28 15:47:38 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
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
		ft_putchar_fd('\n', fd);
	}
}
