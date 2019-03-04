/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:11:11 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/20 13:52:07 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbtree.h>

void		btree_apply_prefix(t_btree *root, void (*applyf)(void*))
{
	if (root)
	{
		applyf(root->item);
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
	}
}
