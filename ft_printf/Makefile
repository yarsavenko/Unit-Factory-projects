#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysavenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 15:39:03 by ysavenko          #+#    #+#              #
#    Updated: 2017/03/11 15:16:28 by ysavenko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

OBJ =   ft_printf.o\
		ft_atoi.o\
		ft_put_nbr.o\
		ft_put_unbr.o\
		ft_put_ulnbr.o\
        ft_strdup.o\
		ft_put_lnbr.o\
		ft_strnew.o\
		ft_strdup.o\
		ft_strjoin.o\
		ft_strlen.o\
		hex.o\
		is.o\
		read_args.o\
		read_flag.o\
		take_mod.o\
		use_flag.o\
		ft_get_lhex.o\
		dop_use_flag.o\
		if_c.o



all: $(NAME)

$(NAME) : $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: ./%.c ft_printf.h
	gcc -Wall -Wextra -Werror -o $@ -c  $< 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all