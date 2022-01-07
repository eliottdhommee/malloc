/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:47:23 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:56:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*search_ptr(t_page *ptr, void *fin)
{
	t_page	*tmp;

	tmp = (t_page*)ptr;
	while (tmp)
	{
		if (((char*)tmp + sizeof(t_page)) == fin)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void		*search_malloc(void *ptr)
{
	void	*tmp;
	void	*res;

	if (ptr == NULL)
		return(NULL);
	tmp = stock_roots(1);
	if ((res = search_ptr(tmp, ptr)))
		return (res);
	tmp = stock_roots(TINY_MALLOC + 1);
	if ((res = search_ptr(tmp, ptr)))
		return (res);
	tmp = stock_roots(SMALL_MALLOC + 1);
	if ((res = search_ptr(tmp, ptr)))
		return (res);
	return (NULL);
}

void		free(void *ptr)
{
	t_page *tmp;

	if (!ptr)
		return ;
	tmp = search_malloc(ptr);
	if (!tmp)
		return ;
	if (tmp->size > SMALL_MALLOC && tmp != stock_roots(SMALL_MALLOC +1) && tmp->free ==FALSE)
	{
		if(tmp->prev)
			(tmp->prev)->next = tmp->next;
		if(tmp->next)
			(tmp->next)->prev = tmp->prev;
		munmap(tmp, tmp->size);
		return;
	}
	if (tmp->next && tmp->size <= SMALL_MALLOC)
	{
		if (tmp->next->first == FALSE && tmp->next->free == TRUE)
		{
			tmp->size = tmp->size + (tmp->next)->size;
			tmp->next = (tmp->next)->next;
		}
	}
	tmp->free = TRUE;
}
