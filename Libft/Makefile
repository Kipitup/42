# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:13:22 by amartino          #+#    #+#              #
#    Updated: 2018/12/18 15:47:32 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi     ft_bzero      ft_isalnum  ft_isalpha    \
      ft_isascii  ft_isdigit    ft_isprint  ft_itoa       \
      ft_lstadd   ft_lstiter    ft_lstmap   ft_lstnew     \
      ft_lstdel   ft_lstdelone  ft_memalloc ft_memchr     \
      ft_memcmp   ft_memccpy    ft_memcpy   ft_memdel     \
      ft_memmove  ft_memset     ft_putchar  ft_putchar_fd \
      ft_putendl  ft_putendl_fd ft_putnbr   ft_putnbr_fd  \
      ft_putstr   ft_putstr_fd  ft_strcat   ft_strchr     \
      ft_strclr   ft_strcmp     ft_strcpy   ft_strdel     \
      ft_strdup   ft_strequ     ft_striter  ft_striteri   \
      ft_strjoin  ft_strlcat    ft_strlen   ft_strmap     \
      ft_strmapi  ft_strncat    ft_strncmp  ft_strncpy    \
      ft_strnequ  ft_strnew     ft_strnstr  ft_strrchr    \
      ft_strsplit ft_strstr     ft_strsub   ft_strtrim    \
      ft_tolower  ft_toupper    ft_strupcase ft_strcapitalize \
      ft_is_prime ft_sort_integer_table ft_max ft_rot ft_intlen \
      ft_countwords ft_count_lst ft_find_lsth

OBJ = $(patsubst %, %.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra

INCLUDES =

CC = gcc

all: $(NAME)

$(OBJ):
	$(CC) -c $(CFLAGS) $(patsubst %, %.c,$(SRC)) -I.

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re ft_isassci
