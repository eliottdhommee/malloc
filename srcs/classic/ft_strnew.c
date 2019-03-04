/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:37:35 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/06 16:08:13 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char			*book;

	if (!(book = malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(book, size + 1);
	return (book);
}
