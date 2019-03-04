/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:30:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/20 13:53:10 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbtree.h>

void		*btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void*, void*))
{
	if (!root)
		return (NULL);
	btree_search_item(root->left, data_ref, cmpf);
	if (!cmpf(root->item, data_ref))
		return (root);
	btree_search_item(root->right, data_ref, cmpf);
	return (NULL);
}
