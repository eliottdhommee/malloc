/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:58:50 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:57:13 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
