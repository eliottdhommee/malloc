/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 18:26:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/15 19:28:46 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_deli(t_list **list, unsigned int i, void (*del)(void*))
{
	t_list		*prev;
	t_list		*tmp;

	tmp = *list;
	prev = tmp;
	while (tmp && --i)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (tmp == *list)
			*list = tmp->next;
		else
			prev->next = tmp->next;
		ft_lstdelone(&tmp, del);
	}
}
