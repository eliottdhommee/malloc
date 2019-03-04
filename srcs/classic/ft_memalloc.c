/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:18:51 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 18:13:15 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	size_t	*book;

	if (!(book = malloc(size * sizeof(size_t))))
		return (NULL);
	ft_bzero(book, size);
	return (book);
}
