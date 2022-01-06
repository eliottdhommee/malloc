/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/06 13:24:58 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

static void	*ft_memcpy2(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}

void	*realloc(void *ptr, size_t size)
{
	char	*tmp;
	t_page	*check;

	if (size == 0 && ptr)
		free(ptr);
	if (size <= 0)
		return (NULL);
	check = search_malloc(ptr);
	if (ptr && (check == NULL))
		return (NULL);
	tmp = malloc(size);
	if (check != NULL)
	{
		if (check->size <= size)
			ft_memcpy2(tmp, ptr, check->size);
		free(ptr);
	}
	return (tmp);
}
