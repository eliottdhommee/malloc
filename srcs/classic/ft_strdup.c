/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:33:30 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/07 19:45:02 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *src)
{
	char		*new;

	if (!(new = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	return (ft_strcpy(new, src));
}
