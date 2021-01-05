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
		page_size = (((TINY_MALLOC + sizeof(t_page) + sizeof(t_rbtree)) * 100) % getpagesize()) + 1;
	else if (size <= SMALL_MALLOC)
		page_size = (((SMALL_MALLOC + sizeof(t_page) + sizeof(t_rbtree)) * 100) % getpagesize()) + 1;
	else
		page_size = ((size + sizeof(t_page) + sizeof(t_rbtree))  % getpagesize()) + 1;
	return (page_size);
}

t_rbtree		*new_node(void *ptr, size_t size)
{
	t_rbtree	*new_node;
	t_page		*new_page;

	if (!ptr)
		return (NULL);
	new_node = (t_rbtree*)ptr;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->color = RB_RED;
	new_page = (t_page*)(new_node + 1);
	new_page->free = TRUE;
	new_page->size = size;
	new_page->data = (void*)(new_page + 1);
	new_node->data = new_page;
	return (new_node);
}

/*
void		*new_page(int size)
{
	size_t	page_len;

	(t_page*)mmap(NULL, page_len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
}
*/
