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

NAME		= libft_malloc_$(HOSTTYPE).a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./srcs/

MALLOC_DIR	= malloc/
MALLOC_SRC	= malloc.c realloc.c free.c page_new.c

BTREE_DIR	= btree/
BTREE_SRC	= btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c\
			  btree_create_node.c btree_insert_data.c btree_level_count.c\
			  btree_search_item.c btree_delete.c

RBTREE_DIR	= rbtree/
RBTREE_SRC	= rb_newnode.c rb_insert.c rb_parents.c rb_rotate.c

PF_DIR		= ft_printf/
PF_SRC		= ft_printf.c pf_buffering.c pf_charstostr.c pf_convgetters.c\
			  pf_convtobuffer.c pf_init.c pf_nbrtostr.c pf_normaltobuffer.c\
			  pf_putconvtobuffer.c pf_setapos.c pf_setprecision.c pf_toolkit.c

LST_DIR		= lst/
LST_SRC		= ft_lstnew.c ft_lstaddback.c ft_lstadd.c ft_lstdelone.c\
			  ft_lstsize.c ft_lstlast.c ft_tabtolst.c ft_lstdel.c ft_lstat.c \
			  ft_lstrev.c ft_lstiter.c ft_lstdelif.c ft_lstsort.c \
			  ft_lstinsert.c ft_lstfind.c ft_deli.c ft_deliend.c \
			  ft_lstfindi.c ft_lstcpy.c ft_lstfindnext.c ft_lstsplit.c \
			  ft_lstsub.c ft_lstsubn.c

CLASSIC_DIR		= classic/
CLASSIC_SRC	= ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_atoi.c\
			  ft_strdup.c ft_strclr.c ft_putendl.c ft_putnbr.c ft_strcpy.c\
			  ft_strncpy.c ft_strcat.c ft_memset.c ft_bzero.c ft_isdigit.c\
			  ft_memcpy.c ft_memccpy.c ft_isalpha.c ft_isalnum.c ft_toupper.c\
			  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
			  ft_strncmp.c ft_striter.c ft_itoa.c ft_strstr.c ft_strnstr.c\
			  ft_memcmp.c ft_memmove.c ft_memchr.c ft_strncat.c ft_strchr.c\
			  ft_strrchr.c ft_isascii.c ft_isprint.c ft_strlcat.c ft_strsub.c\
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
			  ft_strmap.c ft_striteri.c ft_strequ.c ft_strnequ.c ft_strjoin.c\
			  ft_strmapi.c ft_strsplit.c ft_strtrim.c  ft_reverse.c\
			  ft_memcpy_rev.c get_next_line.c ft_wchartoa.c ft_itoa_base.c\
			  ft_strlowcase.c ft_strndup.c ft_tabnew.c ft_tabcpy.c\
			  ft_nbrlen.c ft_tabdup.c ft_tablen.c ft_tabndup.c\
			  ft_strcjoin.c ft_tabdel.c ft_puttab.c ft_getstat.c \
			  ft_getenv.c ft_unsetenv.c ft_putenv.c ft_setenv.c ft_swap_star.c\
			  ft_isnumber.c

LST			= $(addprefix $(LST_DIR),$(LST_SRC))
BTREE		= $(addprefix $(BTREE_DIR),$(BTREE_SRC))
RBTREE		= $(addprefix $(RBTREE_DIR),$(RBTREE_SRC))
PF			= $(addprefix $(PF_DIR),$(PF_SRC))
CLASSIC		= $(addprefix $(CLASSIC_DIR),$(CLASSIC_SRC))
MALLOC		= $(addprefix $(MALLOC_DIR),$(MALLOC_SRC))
FILES		= $(LST) $(BTREE) $(PF) $(CLASSIC) $(RBTREE) $(MALLOC)

SRC			= $(addprefix $(SRC_DIR),$(FILES))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(FILES:.c=.o))

INC			= ./includes/
INCLUDES	= -I $(INC)

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): obj $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

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
