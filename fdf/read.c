/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:16:04 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 16:21:03 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"
#include <stdio.h>

int		read_file(char *name, char **str)
{
	int a;
	int fd;
	int c;

	c = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	(*str) = (char *)malloc(sizeof(char) * 100000);
	while ((a = read(fd, (*str) + c, 1)))
		c++;
	(*str)[c] = '\0';
	c = 0;
	a = 0;
	while ((*str)[c])
	{
		if ((*str)[c] == '\n')
			a++;
		c++;
	}
	return (a);
}

void	cop(char *str, int *a, int *b)
{
	while (str[*a] <= 32)
		(*a)++;
	if (str[*a] == '-')
		(*b)++;
	if (str[*a] == '-' || str[*a] == '+')
		(*a)++;
	while (str[*a] >= '0' && str[*a] <= '9')
	{
		(*a)++;
		(*b)++;
	}
}

int		strn(char *str, char **n, int a, t_node *asd)
{
	int b;

	b = 0;
	cop(str, &a, &b);
	(*n) = (char *)malloc(sizeof(char) * (b + 1));
	(*n)[b] = '\0';
	a = a - b;
	b = 0;
	if (str[a] == '-')
	{
		(*n)[b++] = '-';
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		(*n)[b] = str[a];
		a++;
		b++;
	}
	asd->color = 10777215;
	if (str[a] == ',')
		a += take_color(&str[a], &asd->color);
	return (a);
}

void	fill_map(char *str, t_node ***asd, int lin, int nod)
{
	int		a;
	int		b;
	int		c;
	char	*buff;

	a = 0;
	b = 0;
	c = 0;
	while (b < lin && str[a])
	{
		if (str[a] >= 32)
		{
			asd[b][c] = (t_node *)malloc(sizeof(t_node));
			a = strn(str, &buff, a, asd[b][c]);
			asd[b][c]->z = 0;
			asd[b][c]->z = fdf_atoi(buff);
			c++;
			if (c == nod)
			{
				c = 0;
				b++;
			}
		}
		a++;
	}
}

t_node	***make_map(char *name, int a, int b, int c)
{
	t_node	***kkk;
	char	*str;

	R((c = read_file(name, &str)));
	kkk = (t_node ***)malloc(sizeof(t_node **) * c);
	while (str[a] != '\n')
	{
		while (str[a] <= 32 && str[a] != '\n')
			a++;
		if (str[a] > 32)
		{
			while (str[a] > 32)
				a++;
			b++;
		}
	}
	a = 0;
	while (a < c)
		kkk[a++] = (t_node **)malloc(sizeof(t_node *) * b);
	if (!(a = valid(str, c, b)))
		return (0);
	fill_map(str, kkk, c, b);
	kkk[0][0]->h = c;
	kkk[0][0]->l = b;
	return (kkk);
}
