/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:39 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:17:35 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>

# define TINY_MALLOC 512
# define SMALL_MALLOC 4048

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

void		*new_page(size_t size);
t_page		*fit_block(t_page *root, size_t size);
size_t		get_page_size(size_t size);
t_page		*new_node(void *ptr, size_t size, enum e_bool isfirst);
void		*stock_roots(size_t size);
void		show_alloc_mem(void);
void		print_address_hex(void* p0);
void		*search_malloc(void *ptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *ptr, size_t size);
void		ft_free(void *ptr);
void		*ft_malloc(size_t size);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr(const char *s);
void		write_char(char c);
size_t		ft_strlen(const char *str);
void		*ft_memcpy2(void *dst, const void *src, size_t n);
void		ft_putnbr(int nb);

#endif
