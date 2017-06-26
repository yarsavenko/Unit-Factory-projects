/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:35:55 by ysavenko          #+#    #+#             */
/*   Updated: 2017/01/17 16:54:48 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		get_ret(char *tmpm, char **line, int *b)
{
	int				a;

	a = 0;
	while (tmpm[a] != '\n' && tmpm[a] != '\0')
		a++;
	if (!((*line) = ft_strnew(a)))
		return (-1);
	a = 0;
	while (tmpm[a] != '\n' && tmpm[a] != '\0')
	{
		(*line)[a] = tmpm[a];
		a++;
	}
	(*b) = a;
	return (1);
}

static char		*get_line(char *tmp, char *buff)
{
	char			*ret;

	if (!tmp)
		return (ft_strdup(buff));
	ret = ft_strjoin(tmp, buff);
	free(tmp);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				a;
	int				ret;
	static char		*tmp;

	if (!tmp)
		tmp = ft_strnew(1);
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		R((tmp = get_line(tmp, buff)));
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(tmp))
		return (0);
	R((get_ret(tmp, &(*line), &a)));
	if (a < (int)ft_strlen(tmp))
		ft_memmove(tmp, tmp + (a + 1), ft_strlen(tmp) - a);
	else
		ft_strclr(tmp);
	return (1);
}
