# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thaley <thaley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 17:12:23 by thaley            #+#    #+#              #
#    Updated: 2019/03/20 21:32:25 by thaley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(CFLAGS) -c $(SRC) libft/libft.h
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean :
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re : fclean all
