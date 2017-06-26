/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:02:00 by ysavenko          #+#    #+#             */
/*   Updated: 2017/03/16 18:33:25 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 1

# define R(x) if (!x) return (-1);

typedef struct		s_data
{
	int				x;
	int				y;
	int				pl_n;
	char			pl;
	char			enem;
	int				l;
	int				h;
	char			*fig;
	char			*map;
	int				xret;
	int				yret;
	int				enemy[2];
	int				**pos_pos;
	int				pos_count;
	int				home_side;
	int				enemy_side;
	int				e_s_get;
	int				h_s_get;
	int				count;
	int				get_top;
	int				get_bot;
}					t_data;

typedef struct		s_node
{
	double			x;
	double			y;
	char			z;
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
	char			*qqq;
	t_data			*data;
}					t_fdf;

int					get_next_line(const int fd, char **line);
int					str_filler(char *big, char *little);
void				find_razm(char *line, t_data **data);
void				take_map(char *line, t_data **data);
void				take_fig(char *line, t_data **data);
void				convert(t_data **data);
void				converta(char *str, char *map);
void				find_enemy(t_data **data);
void				puter(t_data **data, int **mass, int **mapi);
void				find_optimal(int *x, int *y, t_data *data, int c);
t_node				***make_map(char *name, int a, int b, int c);
int					find_center(t_node ***node, t_fdf *my, int a);
void				draw(t_node ***nd, t_fdf *my);
int					find_shag(t_node ***n);
int					find_color(t_node *n0, t_node *n1, int x);
int					valid(char *str, int a, int b);
char				**ft_strsplita(char *str);
int					keycode(int keycode, t_fdf *my);
void				swap(t_node ***nd);
int					fdf_atoi(char *str);
unsigned int		take_color(char *str, unsigned int *col);
void				multi_z(t_node ***asd, double m, int flag);
void				fill_xnode(t_node ***node, int alpha, int shag, int balpha);
void				make_pic(t_data **data, char **line, t_fdf **my);
void				draw2(t_node ***nd, t_fdf *my);
void				inner_fil(char **line, t_data **data, t_fdf *my);

#endif
