/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:05:11 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 15:31:53 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_lstdelif(t_list **lst, void *dataref, int (*cmp)(void*, void*),
		void (*del)(void*))
{
	t_list		*prev;
	t_list		*tmp;

	tmp = *lst;
	prev = tmp;
	while (tmp)
	{
		if (cmp(dataref, tmp->data) == 0)
		{
			if (tmp != *lst)
				prev->next = tmp->next;
			else
				*lst = tmp->next;
			ft_lstdelone(&tmp, del);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
