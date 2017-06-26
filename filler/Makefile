# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 19:37:39 by ysavenko          #+#    #+#              #
#    Updated: 2017/02/24 19:57:59 by ysavenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FLAGS = -Wall -Wextra -Werror

SRC = convert.c find_enemy.c find_razm.c put_fig.c take_fig.c fil.c \
	  find_optimal.c get_next_line.c str_filler.c take_map.c center.c \
	   fdf_atoi.c multi_z.c take_color.c draw.c fill_xnode.c read.c \
	   valid.c fdf.c keycode.c swap.c draw2.c

OBJ = $(SRC:.c=.o)

HEAD = ./get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) libft/libft.a -o $(NAME) -lmlx -framework OpenGl -framework AppKit

%.o: %.c
	gcc -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all
