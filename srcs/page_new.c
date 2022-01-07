/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:14 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:15:34 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

size_t			get_page_size(size_t size)
{
	size_t page_size;

	if (size <= TINY_MALLOC)
		page_size = ((TINY_MALLOC * 100) / getpagesize() + 1) * getpagesize();
	else if (size <= SMALL_MALLOC)
		page_size = ((SMALL_MALLOC * 100) / getpagesize() + 1) * getpagesize();
	else
		page_size = ((size / getpagesize()) + 1) * getpagesize();
	return (page_size);
}

void			*new_page(size_t size)
{
	void	*tmp;
	size_t	page_size;

	page_size = get_page_size(size);
	tmp = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0);
	return (new_node(tmp, page_size , TRUE));
}

t_page			*new_node(void *ptr, size_t size, enum e_bool isfirst)
{
	t_page		*new_page;

	if (!ptr)
		return (NULL);
	new_page = (t_page*)ptr;
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
			root_tiny = new_page(size);
		return (root_tiny);
	}
	if (size <= SMALL_MALLOC)
	{
		if (!root_small)
			root_small = new_page(size);
		return (root_small);
	}
	else
	{
		if (!root_large)
			root_large = new_page(size);
		return (root_large);
	}
}
