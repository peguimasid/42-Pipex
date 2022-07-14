# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:42:45 by gmasid            #+#    #+#              #
#    Updated: 2022/07/14 19:41:26 by gmasid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=pipex
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -Iheaders/
LIBFT=./ft_printf/libft/libft.a
FT_PRINTF=./ft_printf/libftprintf.a
SRC=./src/pipex.c ./src/utils.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	cd ft_printf && make
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
	rm -f $(OBJ)
	cd ft_printf && make clean

fclean: clean
	rm -f $(NAME)
	cd ft_printf && make fclean

re: fclean all

.PHONY: clean fclean all re