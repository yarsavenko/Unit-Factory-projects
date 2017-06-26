/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:26:41 by ysavenko          #+#    #+#             */
/*   Updated: 2017/02/06 16:20:13 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define R(x) if (!x) return (0);

typedef struct		s_node
{
	double			x;
	double			y;
	int				z;
	int				l;
	int				h;
	unsigned int	color;
}					t_node;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_node			***asd;
	int				angle;
	int				xangle;
	int				x;
	int				y;
	int				shag;
	double			m;
	int				fm;
}					t_fdf;

t_node				***make_map(char *name, int a, int b, int c);
int					find_center(t_node ***node, t_fdf *my, int a);
void				draw(t_node ***nd, t_fdf *my);
int					find_shag(t_node ***n);
int					find_color(t_node *n0, t_node *n1, int x);
int					valid(char *str, int a, int b);
char				**ft_strsplit(char *str);
int					keycode(int keycode, t_fdf *my);
void				swap(t_node ***nd);
int					fdf_atoi(char *str);
unsigned int		take_color(char *str, unsigned int *col);
void				multi_z(t_node ***asd, double m, int flag);
void				fill_xnode(t_node ***node, int alpha, int shag, int balpha);

#endif
