/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:45:39 by edhommee          #+#    #+#             */
/*   Updated: 2019/10/22 14:57:45 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <librb.h>

# define TINY_MALLOC 512
# define SMALL_MALLOC 2048

enum				e_is_free
{
	TRUE,
	FALSE
};

typedef	struct		s_page
{
	enum e_is_free	free;
	size_t			size;
	void			*data;

}					t_page;

void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		show_alloc_mem();

#endif
