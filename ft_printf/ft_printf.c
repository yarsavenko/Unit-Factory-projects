/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:58:59 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 21:44:30 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_str;

int		filling_my(t_print **my, char *str, int a)
{
	while (str[a] && (is_flag(str[a]) || is_type(str[a]) ||
		str[a] == '.' || is_digit(str[a]) || is_mod(str[a])))
	{
		if (!(*my)->mod)
			take_mod(&str[a], &(*my));
		while (is_flag(str[a]))
			read_flag(str[a++], &(*my));
		if (is_type(str[a]) && !(*my)->type)
		{
			(*my)->type = str[a++];
			break ;
		}
		if (is_digit(str[a]))
			(*my)->mn_pl = ft_atoi(&str[a], &a);
		if (str[a] == '.')
			(*my)->to4 = ft_atoi(&str[++a], &a);
		if (is_mod(str[a]))
			a++;
	}
	return (a);
}

int		if_p(int a, int *count, t_print **my, va_list args)
{
	char *str;

	str = g_str;
	a = filling_my(&(*my), str, a);
	if (str[a] && str[a] != '%' && (*my)->sss == '\0')
		(*my)->sss = str[a++];
	if (str[a] == '%' && (*my)->sss == '\0' && (*my)->type == 0 && (a++))
		(*my)->sss = '%';
	(*my)->count = (*count);
	(*count) += read_args(&(*my), args);
	while (str[a] && str[a] != '%' && (*my)->sss != '\0' && ((*count)++))
		write(1, &str[a++], 1);
	return (a);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			a;
	t_print		*my;
	int			count;

	a = 0;
	count = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str[a] == '%')
		{
			my = (t_print *)malloc(sizeof(t_print));
			init_my(&my);
			a++;
			g_str = str;
			a = if_p(a, &count, &my, args);
		}
		else
		{
			write(1, &str[a++], 1);
			count++;
		}
	}
	return (count);
}
