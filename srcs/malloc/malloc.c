/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2021/01/11 11:43:13 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

int			get_size_type(size_t size)
{
	if (size <= TINY_MALLOC)
		return(1);
	else if (size <= SMALL_MALLOC)
		return(2);
	else
		return(3);
}

int			align_size(int size)
{
	size = (size + 15) & ~15;
	return (size);
}

void		*new_page(size_t size)
{
	return (mmap(NULL, get_page_size(size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0));
}

t_page		*search_free_space(t_page **root, size_t size)
{
	t_page		*tmp;
	t_page		*new;
	t_page		*tmp_next;

	if (!*root)
		*root = new_node(new_page(size), size);
	tmp = *root;
	while (tmp && tmp->free == FALSE && tmp->size <= size)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->free = FALSE;
		if (tmp->size - size > sizeof(t_page))
		{
			tmp_next = tmp->next;
			tmp->next = new_node(((char*)tmp + size), tmp->size - size);
			(tmp->next)->prev = tmp;
			(tmp->next)->next = tmp_next;
			tmp->size = size;
		}
		return(tmp);
	}
}

void		*malloc(size_t size)
{
	static t_page		**root_tiny;
	static t_page		**root_small;
	static t_page		**root_large;
	t_page				*free_space;

	if (size == 0)
		return (NULL);
	free_space = search_free_space(root_tiny, size);
}
