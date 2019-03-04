/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:53:52 by edhommee          #+#    #+#             */
/*   Updated: 2017/12/12 15:09:53 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_lstadd(t_list **begin_list, void *data)
{
	t_list		*tmp;

	if (*begin_list)
	{
		tmp = ft_lstnew(data);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_lstnew(data);
}
