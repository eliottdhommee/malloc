/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/17 09:29:08 by edhommee         ###   ########.fr       */
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
	size = size + sizeof(t_page);
	size = (size  + 15) & ~15 ;
	return (size);
}

void		*new_page(size_t size)
{
	void	*tmp;
	size_t	page_size;

	page_size = get_page_size(size);
	tmp = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	return (new_node(tmp, page_size, TRUE));
}

void		set_new_node(t_page *ptr, size_t size)
{

	t_page		*tmp;

	tmp = ptr->next;
	ptr->next = new_node((char*)ptr + size , ptr->size - size, FALSE);
	(ptr->next)->prev = ptr;
	ptr->size = size;
}

t_page		*search_free_space(t_page *root, size_t size)
{
	t_page		*tmp;
	t_page		*tmp_prev;

	tmp = root;
	while (tmp && tmp->free == FALSE && tmp->size <= size)
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->size >= size && tmp->free == TRUE)
	{
		if (tmp->size - size > 2 * sizeof(t_page))
			set_new_node(tmp, size);
		tmp->free = FALSE;
	}
	else if (tmp)
	{
		tmp->next = new_node(new_page(size), get_page_size(size) - sizeof(t_page), TRUE);
		set_new_node(tmp->next, size);
		tmp = tmp->next;
		tmp->free = FALSE;
	}
	else
	{
		tmp = tmp_prev;
		tmp->next = new_node(new_page(size), get_page_size(size) - sizeof(t_page), TRUE);
		set_new_node(tmp, size);
		tmp = tmp->next;
		tmp->free = FALSE;
	}
	return(tmp);
}

void		*malloc(size_t size)
{
	t_page				*root;
	t_page				*free_space;

	if (size == 0)
		return (NULL);
	size = align_size(size);
	root = stock_roots(size);
	free_space = fit_block(root, size);
	return ((char*)free_space + sizeof(t_page));
}
