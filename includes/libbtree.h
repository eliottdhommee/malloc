/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:15:06 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:27:16 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBTREE_H
# define LIBBTREE_H

# include <stdlib.h>

typedef	struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*btree_create_node(void *item);
void				btree_insert_data(t_btree **root,
							void *item, int (*cmpf)(void*, void*));
void				btree_apply_prefix(t_btree *root, void(*applyf)(void*));
void				btree_apply_infix(t_btree *root, void(*applyf)(void*));
void				btree_apply_suffix(t_btree *root, void(*applyf)(void*));
void				btree_apply_by_level(t_btree *root, void (*applyf)
							(void *item, int current_level, int is_first_elem));
void				*btree_search_item(t_btree *root,
							void *data_ref, int (*cmpf)(void*, void*));
int					btree_level_count(t_btree *root);
void				btree_delete(t_btree *root, void (*del_item)(void*));

#endif
