/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:56:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

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
		{
			ft_memcpy2(tmp, ptr, check->size - sizeof(t_page));
		}
		else
		{
			ft_memcpy2(tmp, ptr, size);
		}
		free(ptr);
	}
	return (tmp);
}
