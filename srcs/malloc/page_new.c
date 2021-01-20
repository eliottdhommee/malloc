/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:14 by edhommee          #+#    #+#             */
/*   Updated: 2021/01/20 09:45:57 by edhommee         ###   ########.fr       */
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

t_page		*new_node(void *ptr, size_t size)
{
	t_page		*new_page;

	if (!ptr)
		return (NULL);
	new_page= (t_page*)ptr;
	new_page->next = NULL;
	new_page->prev = NULL;
	new_page->free = TRUE;
	new_page->size = size;
	return (new_page);
}

void	insert_data(t_page **root, size_t size)
{
}

/*

	t_page	*tmp;

	if (*root)
	{
		tmp = new_node();
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*root= new_node(size);
}
*/
