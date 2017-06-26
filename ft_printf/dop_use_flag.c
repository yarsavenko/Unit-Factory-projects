/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_use_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:20:59 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 21:41:13 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_p(t_print **my)
{
	char *buff;

	buff = (*my)->ret;
	(*my)->ret = "0x";
	if (!(buff[0] == '0' && ft_strlen(buff) == 1) || (*my)->to4 == -1)
		(*my)->ret = ft_strjoin((*my)->ret, buff);
}

void		cut_str(t_print **my)
{
	char	*buff;
	int		a;

	a = 0;
	buff = (*my)->ret;
	(*my)->ret = ft_strnew((*my)->to4);
	while (a < (*my)->to4)
	{
		(*my)->ret[a] = buff[a];
		a++;
	}
}

void		make_resh(t_print **my)
{
	char	*buff;
	int		a;
	size_t	b;

	b = 0;
	while ((*my)->ret[b] == '0' && (*my)->ret[b + 1] == '0')
		b++;
	if (b + 1 == ft_strlen((*my)->ret))
		b = 0;
	a = 2;
	if ((*my)->type == 'o' || (*my)->type == 'O')
		a = 1;
	if (((*my)->ret[0] != '0' && ft_strlen((*my)->ret)) ||
		(ft_strlen((*my)->ret) > 1 && a != 1 && b && (*my)->to4 != -1))
	{
		buff = (*my)->ret;
		(*my)->ret = ft_strnew(a);
		(*my)->ret[0] = '0';
		if (a == 2)
			(*my)->ret[1] = (*my)->type;
		(*my)->ret = ft_strjoin((*my)->ret, buff);
	}
	if (ft_strlen((*my)->ret) >= 2 && a == 2 && b)
		(*my)->ret[1] = (*my)->type;
}

void		make_prob(t_print **my)
{
	char *buff;

	if (((*my)->type == 'd' || (*my)->type == 'D' || (*my)->type == 'i')
		&& (*my)->ret[0] != ' ')
	{
		if ((*my)->ret[0] == '0' && (*my)->nolik)
			(*my)->ret[0] = ' ';
		else if ((*my)->ret[0] == '-')
			(*my)->ret[0] = '-';
		else
		{
			buff = (*my)->ret;
			(*my)->ret = ft_strnew(1);
			(*my)->ret[0] = ' ';
			(*my)->ret = ft_strjoin((*my)->ret, buff);
		}
	}
}

void		last_if(t_print **my, int m, char *buff)
{
	if (m)
		(*my)->ret = ft_strjoin((*my)->ret, buff);
	else
		(*my)->ret = ft_strjoin(buff, (*my)->ret);
}
