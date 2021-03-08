/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2021/03/08 12:05:23 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*realloc(void *ptr, size_t size)
{
	char *tmp;
	t_page *check;

	//ft_putstr_fd("realloc : ", 2);
	//print_address_hex(ptr);
	if (size <= 0)
		return (NULL);
	check = search_malloc(ptr);
	if (ptr && (check == NULL))
		return(ptr);
	tmp = malloc(size);
	if (check != NULL)
	{
		ft_memcpy(tmp, ptr, check->size - sizeof(t_page));
		free(ptr);
	}
	//print_address_hex(tmp);
	return (tmp);
}
