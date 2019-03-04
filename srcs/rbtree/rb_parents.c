/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_parents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:16:29 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/15 17:53:17 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <librb.h>

int				rb_whichson(t_rbtree *node)
{
	if (rb_p(node) == NULL)
		return (0);
	if (node == rb_p(node)->left)
		return (1);
	else
		return (2);
}

t_rbtree		*rb_p(t_rbtree *node)
{
	return (node->parent);
}

t_rbtree		*rb_gp(t_rbtree *node)
{
	if (rb_p(node) == NULL)
		return (NULL);
	else
		return (rb_p(rb_p(node)));
}

t_rbtree		*rb_s(t_rbtree *node)
{
	t_rbtree	*parent;

	parent = rb_p(node);
	if (parent == NULL)
		return (NULL);
	if (node == parent->left)
		return (parent->right);
	else
		return (parent->left);
}

t_rbtree		*rb_u(t_rbtree *node)
{
	if (rb_p(node) == NULL || rb_gp(node) == NULL)
		return (NULL);
	return (rb_s(rb_p(node)));
}
