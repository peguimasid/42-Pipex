# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:42:45 by gmasid            #+#    #+#              #
#    Updated: 2022/07/11 12:33:20 by gmasid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=pipex
CFLAGS=-Wall -Wextra -Werror
OPTIONS=-c -Iheaders/
LIBFT=./libft/libft.a
SRC=pipex.c utils.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(OPTIONS) $(SRC)

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: clean fclean all re