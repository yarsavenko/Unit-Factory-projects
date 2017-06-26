/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:21:55 by ysavenko          #+#    #+#             */
/*   Updated: 2016/12/03 11:21:55 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t len;

	if (!*little)
		return (char*)(big);
	len = ft_strlen(little);
	while (*big)
	{
		if (ft_strncmp(big++, little, len) == 0)
			return (char *)big - 1;
	}
	return (0);
}
