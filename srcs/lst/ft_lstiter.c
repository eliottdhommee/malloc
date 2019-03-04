/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:48:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/13 15:00:35 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_lstiter(t_list *begin_list, void (*f)(t_list *elem))
{
	t_list		*list;

	list = begin_list;
	while (list)
	{
		(*f)(list);
		list = list->next;
	}
}
