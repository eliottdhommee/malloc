/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:26:26 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 19:57:35 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy_rev(void *dst, const void *src, size_t len)
{
	if (!len || dst == src)
		return (dst);
	while (len--)
		((char*)dst)[len] = ((char*)src)[len];
	return (dst);
}
