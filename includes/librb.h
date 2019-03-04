/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:21:25 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/15 19:45:26 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRB_H
# define LIBRB_H

#include <stdlib.h>

enum				e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef	struct		s_rbtree
{
	struct s_rbtree	*parent;
	struct s_rbtree	*right;
	struct s_rbtree	*left;
	void			*data;
	enum e_rb_color	color;
}					t_rbtree;

t_rbtree			*rb_p(t_rbtree *node);
t_rbtree			*rb_gp(t_rbtree *node);
t_rbtree			*rb_s(t_rbtree *node);
t_rbtree			*rb_u(t_rbtree *node);
int					rb_whichson(t_rbtree *node);
void				left_rotate(t_rbtree *a, t_rbtree **root);
void				right_rotate(t_rbtree *a, t_rbtree **root);
t_rbtree			*rb_newnode(void *item);
void				rb_insert(t_rbtree **root, void *data,
		int (*cmpf)(void*, void*));

#endif
