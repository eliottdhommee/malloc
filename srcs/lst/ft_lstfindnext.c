/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:11:46 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/10 17:13:29 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

t_list		*ft_lstfindnext(t_list *begin, void *dataref,
		int (*cmp)(void*, void*))
{
	t_list		*list;

	list = begin;
	while (list && list->next && cmp(dataref, list->next->data) != 0)
		list = list->next;
	return (list);
}
