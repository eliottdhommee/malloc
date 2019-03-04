/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:32:58 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:10:27 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>
#include <libft.h>

void		ft_lstsort(t_list **lst, int (*cmp)(void*, void*))
{
	t_list		*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (cmp(tmp->data, tmp->next->data) > 0)
		{
			ft_swap_star(&(tmp->data), &(tmp->next->data));
			tmp = *lst;
		}
		else
			tmp = tmp->next;
	}
}
