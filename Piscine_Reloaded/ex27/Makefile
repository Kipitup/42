# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 12:04:04 by amartino          #+#    #+#              #
#    Updated: 2018/11/09 14:18:45 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
OBJ = ft_display_file.o
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ):
	gcc -c $(FLAG) $(SRC)

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
