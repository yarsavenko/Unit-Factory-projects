/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:01:26 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/19 13:03:33 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_filler(char *big, char *little)
{
	size_t len;

	len = ft_strlen(little);
	while (*big)
	{
		if (ft_strncmp(big++, little, len) == 0)
			return (1);
	}
	return (0);
}
