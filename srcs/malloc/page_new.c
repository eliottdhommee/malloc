/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:14 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/12 12:13:02 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

size_t			get_page_size(size_t size)
{
	size_t page_size;

	if (size <= TINY_MALLOC)
		page_size = (((TINY_MALLOC + sizeof(t_page)) * 100) / getpagesize()) * (getpagesize() + 1);
	else if (size <= SMALL_MALLOC)
		page_size = (((SMALL_MALLOC + sizeof(t_page)) * 100) / getpagesize()) * (getpagesize() + 1);
	else
		page_size = ((size + sizeof(t_page))  / getpagesize()) * (getpagesize() + 1);
	return (page_size);
}

t_page		*new_node(void *ptr, size_t size, enum e_bool isfirst)
{
	t_page		*new_page;

	if (!ptr)
		return (NULL);
	new_page= (t_page*)ptr;
	new_page->next = NULL;
	new_page->prev = NULL;
	new_page->free = TRUE;
	new_page->size = size;
	new_page->first = isfirst;
	return (new_page);
}

void			*stock_roots(size_t size)
{
	static t_page		*root_tiny = NULL;
	static t_page		*root_small = NULL;
	static t_page		*root_large = NULL;

	if (size <= TINY_MALLOC)
	{
		if (!root_tiny)
			root_tiny = new_node(new_page(size), get_page_size(size), TRUE);
		return (&root_tiny);
	}
	if (size <= SMALL_MALLOC)
	{
		if (!root_small)
			root_small = new_node(new_page(size), get_page_size(size), TRUE);
		return (&root_small);
	}
	else
	{
		if (!root_large)
			root_large = new_node(new_page(size), size, TRUE);
		return (&root_large);
	}
}
