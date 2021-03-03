/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:39 by edhommee          #+#    #+#             */
/*   Updated: 2021/03/02 11:54:25 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include "../libft/includes/libft.h"

# define TINY_MALLOC 512
# define SMALL_MALLOC 2048

enum				e_bool
{
	TRUE,
	FALSE
};

typedef	struct		s_page
{
	struct s_page	*prev;
	struct s_page	*next;
	enum e_bool		free;
	enum e_bool		first;
	size_t			size;

}					t_page;

void		*ft_malloc(size_t size);
void		*new_page(size_t size);
t_page		*fit_block(t_page *root, size_t size);
void		ft_free(void *ptr);
size_t		get_page_size(size_t size);
t_page		*new_node(void *ptr, size_t size, enum e_bool isfirst);
void		*stock_roots(size_t size);
void		*ft_realloc(void *ptr, size_t size);
void		show_alloc_mem();
void		*ft_calloc(size_t nmemb, size_t size);
void		print_address_hex(void* p0);
void		*search_malloc(void *ptr);

#endif
