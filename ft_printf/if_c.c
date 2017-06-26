/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:56:53 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 18:28:34 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_c(va_list args, t_print **my, int *b, char **str)
{
	if ((*my)->type == 'C')
		(*my)->type = 'c';
	(*str) = malloc(sizeof(char) * 2);
	(*str)[1] = '\0';
	(*str)[0] = va_arg(args, int);
	if ((*str)[0] == -1)
		(*my)->is_s_n = 1;
	if ((*str)[0] == 0)
		(*str)[0] = -1;
	*b = *b;
}

void	make_b(t_print **my, char **str)
{
	int *c;

	if (((*my)->mod == 0 || (*my)->mod == 4) && (*my)->type == 'b')
		(*str) = ft_get_hex((unsigned int)(*my)->arg, (*my)->type, 2);
	if ((*my)->mod == 2 && (*my)->type == 'b')
		(*str) = ft_get_hex((unsigned short)(*my)->arg, (*my)->type, 2);
	if ((*my)->mod == 3 && (*my)->type == 'b')
		(*str) = ft_get_hex((unsigned char)(*my)->arg, (*my)->type, 2);
	if ((*my)->mod == 1 && (*my)->type == 'b')
		(*str) = ft_get_lhex((unsigned long)(*my)->arg, (*my)->type, 2);
	if ((*my)->type == 'p')
		(*str) = ft_get_lhex((unsigned long)(*my)->arg, 'x', 16);
	if ((*my)->type == 'n')
	{
		(*str) = ft_strnew(1);
		c = (int *)(*my)->arg;
		(*c) = (*my)->count;
	}
}
