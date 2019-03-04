/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:29:12 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/15 19:28:02 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <librb.h>
#include <libft.h>

t_rbtree		*rb_newnode(void *item)
{
	t_rbtree		*new_node;

	new_node = (t_rbtree*)ft_memalloc(sizeof(t_rbtree));
	if (!new_node)
		return (NULL);
	else
	{
		new_node->data = item;
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->color = RB_RED;
	}
	return (new_node);
}
