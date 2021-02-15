# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edhommee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:49:17 by edhommee          #+#    #+#              #
#*   Updated: 2017/09/07 19:54:29 by edhommee         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
		HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		= libft_malloc_$(HOSTTYPE).so

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= ./srcs/

MALLOC_DIR	= malloc/
MALLOC_SRC	= malloc.c realloc.c free.c page_new.c

MALLOC		= $(addprefix $(MALLOC_DIR),$(MALLOC_SRC))
FILES		= $(MALLOC)

SRC			= $(addprefix $(SRC_DIR),$(FILES))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(FILES:.c=.o))

INC			= ./includes/
INCLUDES	= -I $(INC)

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): obj $(OBJ)
	$(CC) $(CFLAGS) -shared $(OBJ) -o $(NAME)
	@ln -sf $(NAME) libft_malloc.so

obj:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(LST_DIR)
	mkdir -p $(OBJ_DIR)$(BTREE_DIR)
	mkdir -p $(OBJ_DIR)$(RBTREE_DIR)
	mkdir -p $(OBJ_DIR)$(PF_DIR)
	mkdir -p $(OBJ_DIR)$(CLASSIC_DIR)
	mkdir -p $(OBJ_DIR)$(MALLOC_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
