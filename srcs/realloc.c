/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/25 11:21:57 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*realloc(void *ptr, size_t size)
{
	char *tmp;
	t_page *check;

	check = NULL;
	ft_putstr_fd("realloc : ", 2);
	print_address_hex(ptr);
	if (size <= 0)
		return (NULL);
	ft_putnbr_fd(size, 2);
	check = search_malloc(ptr);
	if (ptr && check == NULL)
		return(NULL);
	tmp = malloc(size);
	if (check != NULL)
	{
		ft_putnbr_fd(check->size, 2);
		tmp = ft_strcpy(tmp, ptr);
		free(ptr);
	}
	print_address_hex(tmp);
	return (tmp);
}
