/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:27:47 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 21:37:28 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
