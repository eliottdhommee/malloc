/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/24 11:50:45 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*realloc(void *ptr, size_t size)
{
	char *tmp;

	write(2, "4", 1);
	tmp = malloc(size);
	tmp = ft_strcpy(tmp, ptr);
	free(ptr);
	write(2, "5", 1);
	return (tmp);
}
