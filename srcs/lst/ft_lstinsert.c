/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:44:02 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:23:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_lstinsert(t_list **lst, void *data, int (*cmp)(void*, void*))
{
	t_list		*prev;
	t_list		*tmp;
	t_list		*new;

	tmp = *lst;
	prev = NULL;
	while (tmp && cmp(data, tmp->data) >= 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
	{
		new = ft_lstnew(data);
		new->next = *lst;
		*lst = new;
	}
	else
	{
		new = ft_lstnew(data);
		new->next = tmp;
		prev->next = new;
	}
}
