/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:20:39 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 18:47:03 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	int				i;

	if ((s1 == NULL) && (s2 == NULL) && (n == 0))
		return (0);
	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (i < (int)n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
