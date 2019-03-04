/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:22:00 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/12 11:42:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	if (!n)
		return (s);
	dest = (unsigned char *)s;
	while (n--)
		*dest++ = (unsigned char)c;
	return (s);
}
