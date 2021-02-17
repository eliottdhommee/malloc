/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:24:58 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/16 12:11:24 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

t_page		*block_search(t_page *root, size_t size)
{
	t_page		*tmp;
	t_page		*tmp_prev;

	tmp = root;
	while (tmp && !(tmp->free == TRUE && tmp->size >= size))
	{
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		return(tmp);
	else
		return(tmp_prev);
}

t_page		*fit_block(t_page *root, size_t size)
{
	t_page		*tmp;
	t_page		*tmp_next;

	tmp = block_search(root, size);
	if (tmp && tmp->free == TRUE && tmp->size >= size)
	{
		if (tmp->size - size > 2 * sizeof(t_page))
		{
			tmp_next = tmp->next;
			tmp->next = new_node((char*)tmp + size, tmp->size - size, TRUE);
			tmp->free = FALSE;
			tmp->size = size;
			(tmp->next)->next = tmp_next;
		}
		tmp->free = FALSE;
	}
	else
	{
		tmp->next = new_page(size);
		tmp = tmp->next;
		tmp->next = new_node((char*)tmp + size, tmp->size - size, TRUE);
		tmp->free = FALSE;
		tmp->size = size;
	}
	return (tmp);
}