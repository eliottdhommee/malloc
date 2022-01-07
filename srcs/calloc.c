/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:24:25 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 11:55:50 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void	*ft_memset2(void *s, int c, size_t n)
{
	unsigned char	*dest;

	if (!n)
		return (s);
	dest = (unsigned char *)s;
	while (n--)
		*dest++ = (unsigned char)c;
	return (s);
}

void	ft_bzero2(void *s, size_t n)
{
	ft_memset2(s, 0, n);
}

void	*calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (nmemb == 0 || size == 0)
		return (NULL);
	tmp = malloc(nmemb * size);
	ft_bzero2(tmp, nmemb * size);
	return (tmp);
}
