/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:37:35 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:08:46 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>
#include <libft.h>

t_list		*ft_lstnew(void *data)
{
	t_list	*new;

	if (!(new = (t_list*)ft_memalloc(sizeof(t_list*))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
