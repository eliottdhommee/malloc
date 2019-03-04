/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsubn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:56:14 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/14 18:30:07 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

t_list		*ft_lstsubn(t_list **list, int i, int len)
{
	t_list		*tmp;
	t_list		*end;
	t_list		*ret;

	ret = ft_lstat(*list, i);
	end = ft_lstat(*list, i + len - 1);
	if (i)
	{
		tmp = ft_lstat(*list, i - 1);
		tmp->next = end->next;
	}
	else
		*list = end->next;
	end->next = NULL;
	return (ret);
}
