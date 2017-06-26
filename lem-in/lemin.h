/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:41:09 by ysavenko          #+#    #+#             */
/*   Updated: 2017/05/22 13:21:18 by ysavenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# define BUFF_SIZE 1

int				get_next_line(int fd, char **line);
typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	void		*next;
}				t_room;

typedef struct	s_link
{
	char		*r1;
	char		*r2;
	void		*next;
}				t_link;

typedef struct	s_node
{
	char		*name;
	char		*q;
	int			l;
	int			post;
}				t_node;

typedef struct	s_path
{
	int			number;
	char		**path;
	int			count;
	void		*next;
	int			step_left;
	int			ant_n;
}				t_path;

typedef struct	s_ant
{
	int			n_ant;
	int			to_go;
	int			path_n;
	void		*next;
}				t_ant;

typedef struct	s_field
{
	t_room		*start;
	t_room		*end;
	int			count;
	int			count_l;
	t_room		*rooms;
	t_room		*rr;
	int			ants;
	t_link		*links;
	t_link		*ll;
	t_node		*node;
	int			count_path;
	t_path		*path;
	t_path		*pp;
	t_ant		*ant;
	t_ant		*aa;
}				t_field;

void			lem_read(char *str, t_field **m_field);
int				chek_str(char *str, t_field **m_field);
int				take_room(char *str, char c, t_field **m_field);
void			fill_rooms(t_room *room, t_field **m_field, char c);
char			*take_name(char *str, int *b, char c);
int				ft_strcmp(const char *s1, const char *s2);
void			make_node(t_field **m_field, int b);
int				find_path(t_field **field);
int				c_names(t_field **field, char *n1, char *n2);
int				take_path(t_field **field, t_node **node, int b, int a);
int				is_used(t_field **field, t_link *l);
void			move_ant(t_field **field, int b, int a);
int				is_actual(t_field **field, int fastest, t_path *cur, int a);
void			free_node(t_field **field);
int				c_post(t_node *node, int a, char *name);
char			*take_lname(int count, char *str, int *a);
long			atolo(char *str);
int				is_int(char *str, int c);
int				is_validroom(char *str);
char			*take_name(char *str, int *b, char c);
int				take_room(char *str, char c, t_field **m_field);
int				dop_valid(t_field *field, char *str);
int				l_c(char *name, char *name2, t_field *field);
int				count_b(char *str);
#endif
