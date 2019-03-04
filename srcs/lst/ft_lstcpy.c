/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:50:51 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:22:02 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

t_list		*ft_lstcpy(t_list *list)
{
	t_list		*new;

	new = NULL;
	while (list)
	{
		ft_lstaddback(&new, list->data);
		list = list->next;
	}
	return (new);
}
