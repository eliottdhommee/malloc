/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <eliottdhommee@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:25:21 by edhommee          #+#    #+#             */
/*   Updated: 2017/06/26 12:25:23 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlowcase(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		*tmp = ft_tolower((int)*tmp);
		tmp++;
	}
	return (s);
}
