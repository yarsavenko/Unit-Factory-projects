#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 19:11:15 by tgogol            #+#    #+#              #
#    Updated: 2017/05/22 13:42:08 by ysavenko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =	gcc -Wall -Wextra -Werror

NAME =	lem-in

FLSRC = c_post.o \
		chek_str.o 	\
		find_path.o  \
		ft_strcmp.o \
		get_next_line.o \
		is_actual.o \
		is_used.o \
		lemin.o \
		lm_read.o \
		make_node.o \
		move_ant.o \
		take_lname.o \
		take_path.o \
		valid_room.o

all: $(NAME)

$(NAME) : libft.a $(FLSRC)
	$(GCC) $(FLSRC) -o $(NAME) ./libft/libft.a

libft.a:
	make -C ./libft

%.o: %.c
	$(GCC) -o $@ -c $< -I . -I ./libft

clean:
	rm -rf $(FLSRC)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a

re: fclean all