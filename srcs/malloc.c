/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:17 by edhommee          #+#    #+#             */
/*   Updated: 2021/03/04 08:33:32 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

int			get_size_type(size_t size)
{
	if (size <= TINY_MALLOC)
		return (1);
	else if (size <= SMALL_MALLOC)
		return (2);
	else
		return (3);
}

int			align_size(int size)
{
	size = (size + 15) & ~15;
	size = size + sizeof(t_page);
	return (size);
}

void		*ft_malloc(size_t size)
{
	t_page				*root;
	t_page				*free_space;

	//ft_putstr_fd("malloc : ", 2);
	if(size == 0)
		return (NULL);
	size = align_size(size);
	root = stock_roots(size);
	free_space = fit_block(root, size);
	//print_address_hex((char*)free_space + sizeof(t_page));
	return ((char*)free_space + sizeof(t_page));
}
