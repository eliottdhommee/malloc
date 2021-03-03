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
CFLAGS		= -Wall -Wextra -Werror -g
SRC_DIR		= ./srcs/

SRCS		= malloc.c realloc.c free.c page_new.c block_search.c calloc.c show_alloc_mem.c

SRC			= $(addprefix $(SRC_DIR),$(SRCS))

T			= tests/
TESTS		= $Ttest_malloc.c
TEST_LIB	= -L/Users/edhommee/.brew/Cellar/criterion/2.3.3/lib -lcriterion
TEST_INC	= -I/Users/edhommee/.brew/Cellar/criterion/2.3.3/include
OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

INCLUDES	= -I ./includes/ -I ./libft/includes/

LIB_DIR		= ./libft/
LIBFT		= $(LIB_DIR)libft.a
LIB_LINK	= -Llibft -lft

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB_LINK) -shared $(OBJ) -o $(NAME)
	@ln -sf $(NAME) libft_malloc.so
	@printf "\033[0;32m%-50s\033[0m\n" "Compilation done"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIB_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

test:$(NAME)
	gcc $(TESTS) $(NAME) $(INCLUDES) $(TEST_LIB) $(TEST_INC) -o test_malloc
	./test_malloc
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
