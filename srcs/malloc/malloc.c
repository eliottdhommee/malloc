/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/11 09:00:47 by edhommee         ###   ########.fr       */
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
	size = (size  + 15) & ~15 ;
	return (size);
}

void		*new_page(size_t size)
{
	return (mmap(NULL, get_page_size(size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0));
}

t_page		*search_free_space(t_page **root, size_t size)
{
	t_page		*tmp;
	t_page		*tmp_prev;
	t_page		*tmp_next;

	tmp = *root;
	while (tmp && tmp->free == FALSE && tmp->size <= size)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->size >= size && tmp->free == TRUE)
	{
		tmp->free = FALSE;
		if (tmp->size - size > 2 * sizeof(t_page))
		{
			tmp_next = tmp->next;
			tmp->next = new_node(((char*)tmp + size), tmp->size - size, FALSE);
			(tmp->next)->prev = tmp;
			(tmp->next)->next = tmp_next;
			tmp->size = size;
		}
	}
	else if (tmp)
	{
	printf("variable f is at address: %p\n", (void*)tmp_prev);
		tmp->next = new_node(new_page(size), get_page_size(size), TRUE);
		tmp_next = tmp->next;
		tmp->next = new_node(((char*)tmp + size), tmp->size - size, FALSE);
		(tmp->next)->prev = tmp;
		(tmp->next)->next = tmp_next;
		tmp->size = size;
		tmp = tmp->next;
		tmp->free = FALSE;
	}
	return(tmp);
}

void		*ft_malloc(size_t size)
{
	t_page				**root;
	t_page				*free_space;

	if (size == 0)
		return (NULL);
	size = align_size(size);
	root = stock_roots(size);
	free_space = search_free_space(root, size);
	return ((char*)free_space + sizeof(t_page));
}
