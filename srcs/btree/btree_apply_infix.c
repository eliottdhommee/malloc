/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:29:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/20 13:51:54 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbtree.h>

void		btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (root)
	{
		btree_apply_infix(root->left, applyf);
		applyf(root->item);
		btree_apply_infix(root->right, applyf);
	}
}
