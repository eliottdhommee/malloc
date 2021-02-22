/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/22 11:27:21 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*realloc(void *ptr, size_t size)
{
	char *tmp;
ft_printf("%w%lu\n", 2, sizeof(t_page));

	tmp = malloc(size);
	tmp = ft_strcpy(tmp, ptr);
	free(ptr);
	return(tmp);
}
