/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:41:20 by ysavenko          #+#    #+#             */
/*   Updated: 2016/11/30 15:49:21 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, char c)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (s[a] == c)
		a++;
	while (s[a])
	{
		while (s[a] != c && s[a])
			a++;
		count++;
		while (s[a] == c && s[a])
			a++;
	}
	return (count);
}
