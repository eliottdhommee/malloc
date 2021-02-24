/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:47:23 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/24 11:50:39 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		free(void *ptr)
{
	t_page *tmp;

	write(2, "2", 1);
	if (!ptr)
		return ;
	tmp = (t_page*)((char*)ptr - sizeof(t_page));
	tmp->free = TRUE;
	write(2, "3", 1);
}
