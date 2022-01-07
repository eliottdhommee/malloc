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

SRCS		= malloc.c realloc.c free.c page_new.c block_search.c calloc.c \
			  show_alloc_mem.c utils.c

SRC			= $(addprefix $(SRC_DIR),$(SRCS))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INCLUDES	= -I ./includes/

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):$(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -shared $(OBJ) -o $(NAME)
	@ln -sf $(NAME) libft_malloc.so
	@printf "\033[0;32m%-50s\033[0m\n" "Compilation done"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft_malloc.so
	@rm -f $(TEST_NAME)

include tests/tests.mk
re: fclean all
