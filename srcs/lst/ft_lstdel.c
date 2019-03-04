/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:54:49 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:23:02 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void	ft_lstdel(t_list **begin_list, void (*del_item)(void*))
{
	t_list		*tmp;
	t_list		*nxt;

	tmp = *begin_list;
	while (tmp)
	{
		nxt = tmp->next;
		ft_lstdelone(&tmp, del_item);
		tmp = nxt;
	}
	*begin_list = NULL;
}
