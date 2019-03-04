/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:08:00 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/03 20:50:38 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isnumber(char *src)
{
	int		i;

	i = 1;
	if (src[0] && src[0] != '+' && src[0] != '-' && !ft_isdigit(src[0]))
		return (0);
	if ((ft_strlen(src) == 10 && src[0] != '+' && src[0] != '-' &&
			ft_strcmp(src, "2147483647") > 0) ||
			(ft_strlen(src) == 11 && ((src[0] != '+' ||
			ft_strcmp(src, "+2147483647")) > 0 && (src[0] != '-' ||
			ft_strcmp(src, "-2147483648") > 0))) || ft_strlen(src) > 11)
		return (0);
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
			return (0);
		i++;
	}
	return (1);
}
