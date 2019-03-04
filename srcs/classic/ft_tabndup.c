/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:51:00 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/13 13:37:31 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabndup(char **tab, size_t n)
{
	char		**new;
	size_t		i;

	if (!(new = ft_tabnew(n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = ft_strdup(tab[i]);
		++i;
	}
	return (new);
}
