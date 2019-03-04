/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:52:26 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/10 17:20:16 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

t_list		*ft_lstsplit(t_list *lst, void *dataref, int (*cmp)(void*, void*),
		void (*del)(void*))
{
	t_list		*split;
	t_list		*tmp;
	t_list		*nxt;

	tmp = lst;
	while (tmp)
	{
		ft_lstaddback(&split, tmp);
		tmp = ft_lstfindnext(tmp, dataref, cmp);
		if (tmp && tmp->next)
		{
			nxt = tmp->next;
			tmp->next = NULL;
			tmp = nxt->next;
			ft_lstdelone(&nxt, del);
		}
	}
	return (split);
}
