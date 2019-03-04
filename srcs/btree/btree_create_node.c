/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:03:00 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:03:57 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbtree.h>
#include <libft.h>

t_btree		*btree_create_node(void *item)
{
	t_btree		*new_node;

	new_node = (t_btree*)ft_memalloc(sizeof(t_btree));
	if (!new_node)
		return (NULL);
	else
	{
		new_node->item = item;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
