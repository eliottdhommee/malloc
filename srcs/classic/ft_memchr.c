/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:19:46 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 18:47:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chk;
	unsigned char	mark;
	int				i;

	i = 0;
	mark = (unsigned char)c;
	chk = (unsigned char *)s;
	while (i < (int)n)
	{
		if (chk[i] == mark)
			return (&chk[i]);
		i++;
	}
	return (NULL);
}
