# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 16:42:45 by gmasid            #+#    #+#              #
#    Updated: 2022/06/09 12:41:27 by gmasid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c	\
				ft_printf_utils.c	\
				ft_print_ptr.c \
				ft_print_hexa.c	\

OBJS	= $(SRCS:.c=.o)

.c.o:
		cc -Wall -Wextra -Werror -I include -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			cd ./libft && make && cp -v libft.a ../${NAME}
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS) $(BN_OBJS)
		cd ./libft && make clean

fclean:	clean
		rm -f $(NAME)
		cd ./libft && make fclean

re:	fclean all

.PHONY:	all clean fclean re