/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:48:10 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/15 21:14:57 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <librb.h>
#include <libft.h>

void			rb_insertn(t_rbtree **root, t_rbtree *new, t_rbtree *parent,
		int (*cmpf)(void*, void*))
{
	if (!*root)
	{
		new->parent = parent;
		*root = new;
	}
	else
	{
		if (cmpf(((t_rbtree *)*root)->data, new->data) > 0)
			rb_insertn(&((t_rbtree *)*root)->left, new, *root, (*cmpf));
		else
			rb_insertn(&((t_rbtree *)*root)->right, new, *root, (*cmpf));
	}
}

void			rb_insert(t_rbtree **root, void *data,
		int (*cmpf)(void*, void*))
{
	t_rbtree		*n;

	n = rb_newnode(data);
	rb_insertn(root, n, NULL, cmpf);
	while (n->parent != NULL && n->parent->color == RB_RED)
	{
		if (rb_u(n) && rb_u(n)->color == RB_RED)
		{
			rb_p(n)->color = RB_BLACK;
			rb_u(n)->color = RB_BLACK;
			rb_gp(n)->color = RB_RED;
			n = rb_gp(n);
		}
		else
		{
			if (rb_p(n) == rb_gp(n)->left)
			{
				if (n == rb_p(n)->right)
				{
					n = n->parent;
					left_rotate(n, root);
				}
				rb_p(n)->color = RB_BLACK;
				rb_gp(n)->color = RB_RED;
				right_rotate(rb_gp(n), root);
			}
			else
			{
				if (n == rb_p(n)->left)
				{
					n = n->parent;
					right_rotate(n, root);
				}
				rb_p(n)->color = RB_BLACK;
				rb_gp(n)->color = RB_RED;
				left_rotate(rb_gp(n), root);
			}
		}
	}
	((t_rbtree*)*root)->color = RB_BLACK;
}
