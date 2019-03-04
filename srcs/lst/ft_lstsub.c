/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:24:54 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/14 17:40:17 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

t_list		*ft_lstsub(t_list **list, int i)
{
	t_list		*tmp;
	t_list		*ret;

	tmp = *list;
	if (i == 0)
	{
		*list = tmp->next;
		return (tmp);
	}
	while (tmp && --i)
		tmp = tmp->next;
	if (tmp && tmp->next)
	{
		ret = tmp->next;
		tmp->next = ret->next;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}
