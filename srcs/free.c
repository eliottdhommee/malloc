/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:47:23 by edhommee          #+#    #+#             */
/*   Updated: 2021/03/03 10:43:16 by edhommee         ###   ########.fr       */
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

void		ft_free(void *ptr)
{
	t_page *tmp;

	//ft_putstr_fd("free : ", 2);
	//print_address_hex(ptr);
	if (!ptr)
		return ;
	tmp = search_malloc(ptr);
	if (!tmp)
		return ;
	tmp->free = TRUE;
	//print_address_hex(ptr);
}
