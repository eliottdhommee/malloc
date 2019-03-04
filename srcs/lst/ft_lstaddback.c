/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:45:32 by edhommee          #+#    #+#             */
/*   Updated: 2017/12/12 15:17:05 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_lstaddback(t_list **begin_list, void *data)
{
	t_list		*tmp;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(data);
	}
	else
		*begin_list = ft_lstnew(data);
}
