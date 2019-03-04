/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:41:44 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/15 21:06:57 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <librb.h>

void				left_rotate(t_rbtree *a, t_rbtree **root)
{
	t_rbtree	*b;

	b = a->right;
	a->right = b->left;
	if (b->left != NULL)
		b->left->parent = a;
	b->parent = a->parent;
	if (a->parent == NULL)
		*root = b;
	if (a->parent != NULL)
	{
		if (a == rb_p(a)->left)
			rb_p(a)->left = b;
		else
			rb_p(a)->right = b;
	}
	b->left = a;
	a->parent = b;
}

void				right_rotate(t_rbtree *a, t_rbtree **root)
{
	t_rbtree		*b;

	b = a->left;
	a->left = b->right;
	if (b->right != NULL)
		b->right->parent = a;
	b->parent = a->parent;
	if (a->parent == NULL)
		*root = b;
	if (a->parent != NULL)
	{
		if (a == rb_p(a)->left)
			rb_p(a)->left = b;
		else
			rb_p(a)->right = b;
	}
	b->right = a;
	a->parent = b;
}
