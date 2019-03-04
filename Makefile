# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 13:25:56 by edhommee          #+#    #+#              #
#    Updated: 2019/02/07 13:26:04 by edhommee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME 		= libft_malloc_$(HOSTTYPE).so

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs/
SRC_NAME	= malloc.c realloc.c free.c

SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	=  -I ./includes

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): obj $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
