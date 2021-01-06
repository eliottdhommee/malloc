/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2019/10/22 17:17:55 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

int			get_size_type(size_t size)
{
	if (size <= TINY_MALLOC)
		return(1);
	else if (size <= SMALL_MALLOC)
		return(2);
	else
		return(3);
}

int			align_size(int size)
{
	size = (size + 15) & ~15;
	return (size);
}

t_page		*search_free_space(t_page *root, size_t size)
{
	if (!root)
		return (NULL);
	search_free_space((t_page*)root->left, size);
	if (((t_page*)root->item)->free == TRUE && ((t_page*)root->item)->size >= size)
		return (root);
	search_free_space((t_page*)root->right, size);
	return (NULL);
}

void		*malloc(size_t size)
{
	static t_page		**root_tiny;
	static t_page		**root_small;
	static t_page		**root_large;

	if (size == 0)
		return (NULL);
}
