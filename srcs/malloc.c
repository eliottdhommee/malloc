/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:55:06 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <libft_malloc.h>

int			get_size_type(size_t size)
{
	if (size <= TINY_MALLOC)
		return (1);
	else if (size <= SMALL_MALLOC)
		return (2);
	else
		return (3);
}

size_t		align_size(size_t  size)
{
	size = size + sizeof(t_page);
	size = (size + 15) & ~15;
	return (size);
}

void		*malloc(size_t size)
{
	t_page				*root;
	t_page				*free_space;

	if(size == 0)
		return (NULL);
	size = align_size(size);
	root = stock_roots(size);
	free_space = fit_block(root, size);
	return ((char*)free_space + sizeof(t_page));
}
