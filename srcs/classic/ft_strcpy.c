/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:32:10 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/12 16:09:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
