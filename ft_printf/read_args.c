/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:56:46 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/11 18:07:03 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_d2_args(t_print **my, char **str)
{
	if (((*my)->mod == 0 || (*my)->mod == 4) && (*my)->type == 'o')
		(*str) = ft_get_hex((unsigned int)(*my)->arg, (*my)->type, 8);
	if ((*my)->mod == 2 && (*my)->type == 'o')
		(*str) = ft_get_hex((unsigned short)(*my)->arg, (*my)->type, 8);
	if ((*my)->mod == 3 && (*my)->type == 'o')
		(*str) = ft_get_hex((unsigned char)(*my)->arg, (*my)->type, 8);
	if ((*my)->mod == 1 && (*my)->type == 'o')
		(*str) = ft_get_lhex((unsigned long)(*my)->arg, (*my)->type, 8);
	if ((*my)->type == 'O')
		(*str) = ft_get_lhex((unsigned long)(*my)->arg, (*my)->type, 8);
	if (((*my)->mod == 0 || (*my)->mod == 4) && (*my)->type == 'u')
		(*str) = ft_put_unbr((unsigned int)(*my)->arg);
	if ((*my)->mod == 2 && (*my)->type == 'u')
		(*str) = ft_put_nbr((unsigned short)(*my)->arg);
	if ((*my)->mod == 3 && (*my)->type == 'u')
		(*str) = ft_put_nbr((unsigned char)(*my)->arg);
	if ((*my)->mod == 1 && (*my)->type == 'u')
		(*str) = ft_put_ulnbr((unsigned long)(*my)->arg);
	if ((*my)->mod == 4 && (*my)->type == 'u')
		(*str) = ft_put_ulnbr((size_t)(*my)->arg);
	if ((*my)->type == 'U')
		(*str) = ft_put_ulnbr((unsigned long)(*my)->arg);
	else
		make_b(&(*my), &(*str));
}

void	read_d_args(t_print **my, va_list args, char **str)
{
	if ((*my)->type)
		(*my)->arg = va_arg(args, void *);
	if ((*my)->type == 'D')
		(*str) = ft_put_lnbr((long)(*my)->arg);
	if ((*my)->mod == 1 && ((*my)->type == 'd' || (*my)->type == 'i'))
		(*str) = ft_put_lnbr((long)(*my)->arg);
	if ((*my)->mod == 4 && ((*my)->type == 'd' || (*my)->type == 'i'))
		(*str) = ft_put_lnbr((size_t)(*my)->arg);
	if ((*my)->mod == 2 && ((*my)->type == 'd' || (*my)->type == 'i'))
		(*str) = ft_put_nbr((short)(*my)->arg);
	if ((*my)->mod == 3 && ((*my)->type == 'd' || (*my)->type == 'i'))
		(*str) = ft_put_nbr((signed char)(*my)->arg);
	if ((*my)->mod == 0 && ((*my)->type == 'd' || (*my)->type == 'i'))
		(*str) = ft_put_nbr((int)(*my)->arg);
	if (((*my)->mod == 0 || (*my)->mod == 4) && ((*my)->type == 'x' ||
		(*my)->type == 'X'))
		(*str) = ft_get_hex((unsigned int)(*my)->arg, (*my)->type, 16);
	if ((*my)->mod == 3 && ((*my)->type == 'x' || (*my)->type == 'X'))
		(*str) = ft_get_hex((unsigned char)(*my)->arg, (*my)->type, 16);
	if ((*my)->mod == 2 && ((*my)->type == 'x' || (*my)->type == 'X'))
		(*str) = ft_get_hex((unsigned short)(*my)->arg, (*my)->type, 16);
	if ((*my)->mod == 1 && ((*my)->type == 'x' || (*my)->type == 'X'))
		(*str) = ft_get_lhex((unsigned long)(*my)->arg, (*my)->type, 16);
	else
		read_d2_args(&(*my), &(*str));
}

int		write_ret(t_print **my, int a, int b)
{
	while ((*my)->ret[a])
	{
		if ((*my)->ret[a] == -1 && (*my)->is_s_n != 1)
			write(1, "\0", 1);
		else
			write(1, &(*my)->ret[a], 1);
		b++;
		a++;
	}
	if ((*my)->sss != 0)
	{
		b++;
		write(1, &(*my)->sss, 1);
	}
	return (b);
}

void	for_s(t_print **my, va_list args, char **str)
{
	(*str) = va_arg(args, char *);
	if (!(*str))
		(*str) = "(null)";
	(*my)->is_s = 1;
}

int		read_args(t_print **my, va_list args)
{
	char	*str;
	int		b;

	b = 0;
	str = "";
	if ((*my)->type == 's' || (*my)->type == 'S')
		for_s(&(*my), args, &str);
	else if ((*my)->type == 'c' || (*my)->type == 'C')
		if_c(args, &(*my), &b, &str);
	else
		read_d_args(&(*my), args, &str);
	(*my)->ret = str;
	use_flag(&(*my));
	return (write_ret(&(*my), 0, b));
}
