# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 19:37:39 by ysavenko          #+#    #+#              #
#    Updated: 2017/02/06 15:56:04 by ysavenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

OBJ = fdf.o\
        draw.o\
        center.o\
        valid.o\
        read.o\
        keycode.o\
        fdf_atoi.o\
        take_color.o\
		fill_xnode.o\
		multi_z.o\
		swap.o

HEAD = ./fdf.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGl -framework AppKit

$(OBJ): $(HEAD)

%.o: ./%.c
	gcc -o $@ -c -I$(HEAD) $< 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all