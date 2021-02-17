/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:47:23 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/17 08:29:58 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		free(void *ptr)
{
	t_page *tmp;

	if (!ptr)
		return ;
	tmp = (t_page*)((char*)ptr - sizeof(t_page));
	tmp->free = TRUE;
}
