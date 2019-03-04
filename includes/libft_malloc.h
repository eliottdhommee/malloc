/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:24:11 by edhommee          #+#    #+#             */
/*   Updated: 2019/02/07 13:22:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# define TINY_MALLOC 100
# define SMALL_MALLOC 1000
# define LARGE_MALLOC 10000

void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);

#endif
