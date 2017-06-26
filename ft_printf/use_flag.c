/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:20:33 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 21:43:33 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_plus(t_print **my)
{
	char *buff;

	if (((*my)->type == 'd' || (*my)->type == 'i' || (*my)->type == 'D') &&
		(*my)->ret[0] != '-')
	{
		buff = (*my)->ret;
		(*my)->ret = ft_strnew(1);
		(*my)->ret[0] = '+';
		(*my)->ret = ft_strjoin((*my)->ret, buff);
	}
}

char		*make_2nolik(t_print **my, int *f, int n, char c)
{
	char *buff;

	(*my)->e = 0;
	(*f) = ft_strlen((*my)->ret);
	if (c == '0' && (*my)->ret[0] == '-' && n >= (*f) && ((*my)->e = 1))
		(*my)->ret = ft_strdup(&(*my)->ret[1]);
	if (c == '0' && (*my)->ret[0] == '+' && n >= (*f) && ((*my)->e = 2))
		(*my)->ret = ft_strdup(&(*my)->ret[1]);
	if (ft_strlen((*my)->ret))
		buff = (*my)->ret;
	else
		buff = ft_strnew(1);
	if (!ft_strlen((*my)->ret) && (*my)->sss == '\0' && (*my)->minus)
		n = 0;
	return (buff);
}

int			make_nolik(t_print **my, char c, int m, int n)
{
	char	*buff;
	int		a;
	int		b;
	int		f;

	b = 0;
	if (m == 2 && (*my)->ret[0] == '0')
		if ((((*my)->type == 'o' || (*my)->type == 'O') && !(*my)->resh) ||
		((*my)->type == 'i' || (*my)->type == 'x' || (*my)->type == 'd' ||
		(*my)->type == 'X') || (*my)->type == 'u' || (*my)->type == 'U'
		|| (*my)->type == 'D')
			(*my)->ret = ft_strnew(1);
	buff = make_2nolik(&(*my), &f, n, c);
	a = ft_strlen(buff);
	f = (m == 2 && (*my)->e) ? n - a + 1 : n - a;
	if (n > a)
	{
		(*my)->ret = ft_strnew(f);
		while (b < f)
			(*my)->ret[b++] = c;
		(*my)->ret[0] = ((*my)->e == 1) ? '-' : (*my)->ret[0];
		(*my)->ret[0] = ((*my)->e == 2) ? '+' : (*my)->ret[0];
		last_if(&(*my), m, buff);
	}
	return (0);
}

void		use_to4(t_print **my)
{
	if ((*my)->type == 's' || !ft_strlen((*my)->ret))
		cut_str(&(*my));
	else if ((*my)->type != 0)
	{
		make_nolik(&(*my), '0', 2, (*my)->to4);
		(*my)->nolik = 0;
	}
}

void		use_flag(t_print **my)
{
	if ((*my)->ret[0] == '\0' && !(*my)->is_s)
	{
		(*my)->ret = ft_strnew(1);
		(*my)->ret[0] = (*my)->sss;
		(*my)->sss = '\0';
		if ((*my)->ret[0] != 0)
			(*my)->is_s_n = 2;
	}
	if ((*my)->plus && (*my)->type != 'p')
		make_plus(&(*my));
	if ((*my)->to4 != -1 && (*my)->type != 'c')
		use_to4(&(*my));
	if ((*my)->type == 'p')
		make_p(&(*my));
	if ((*my)->nolik && !(*my)->minus)
		make_nolik(&(*my), '0', 1, (*my)->mn_pl);
	if ((*my)->resh && ((*my)->type == 'x' || (*my)->type == 'X' ||
		(*my)->type == 'o' || (*my)->type == 'O'))
		make_resh(&(*my));
	if ((!(*my)->nolik && !(*my)->minus))
		make_nolik(&(*my), ' ', 1, (*my)->mn_pl);
	if ((*my)->minus)
		make_nolik(&(*my), ' ', 0, (*my)->mn_pl);
	if ((*my)->prob && !(*my)->plus && (*my)->type != 'p')
		make_prob(&(*my));
}
