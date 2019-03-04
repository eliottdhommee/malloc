/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:07:20 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/14 13:10:22 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabcpy(char **dest, char **src)
{
	char	**tmp;

	tmp = dest;
	if (dest == src)
		return (dest);
	while (**src)
		*dest++ = *src++;
	*dest = NULL;
	return (tmp);
}
