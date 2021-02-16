/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:47 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/16 08:10:31 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char		*tmp;

	tmp = dest;
	if (dest == src)
		return (dest);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}

void		*realloc(void *ptr, size_t size)
{
	char *tmp;

	tmp = malloc(size);
	tmp = ft_strcpy(tmp, ptr);
	free(ptr);
	return(tmp);
}
