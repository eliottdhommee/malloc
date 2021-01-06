/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:14 by edhommee          #+#    #+#             */
/*   Updated: 2019/10/22 17:18:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

int			get_page_size(int size)
{
	int page_size;

	if (size <= TINY_MALLOC)
		page_size = (((TINY_MALLOC + sizeof(t_page)) * 100) % getpagesize()) + 1;
	else if (size <= SMALL_MALLOC)
		page_size = (((SMALL_MALLOC + sizeof(t_page)) * 100) % getpagesize()) + 1;
	else
		page_size = ((size + sizeof(t_page))  % getpagesize()) + 1;
	return (page_size);
}

t_page		*new_node(void *ptr, size_t size)
{
	t_page		*new_page;

	if (!ptr)
		return (NULL);
	new_page= (t_page*)ptr;
	new_page->left = NULL;
	new_page->right = NULL;
	new_page->free = TRUE;
	new_page->size = size;
	new_page->item = (void*)(new_page + 1);
	return (new_page);
}

void	insert_data(t_page **root, size_t size)
{
	if (!*root)
		*root = new_node(size);
	else
	{
		if (size < (*root)->size)
			insert_data(&((t_page*)*root)->left, item);
		else
			insert_data(&((t_page*)*root)->right, item);
	}
}

/*
void		*new_page(int size)
{
	size_t	page_len;

	(t_page*)mmap(NULL, page_len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
}
*/
