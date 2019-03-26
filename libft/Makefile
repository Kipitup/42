# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:13:22 by amartino          #+#    #+#              #
#    Updated: 2019/03/26 15:43:00 by amartino         ###   ########.fr        #
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
      ft_countwords ft_count_lst ft_find_lsth ft_find_square ft_lstadd_new \
	  ft_memchr_last

OBJ = $(patsubst %, %.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

HEAD = ./libft.h

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< $(INCLUDES)
	@echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)OBJ$(END) \t\t were \t\t $(GREEN)clean$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)$(NAME)$(END) \t were \t\t $(GREEN)clean$(END)"

re: fclean all

.PHONY: clean fclean all re ft_isassci

							#####################
							#                   #
							#        GIT        #
							#                   #
							#####################
git:
	@git add -f *
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push
							#####################
							#                   #
							#       COLOR       #
							#                   #
							#####################
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m
