/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:35:08 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/12 13:44:25 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabdup(char **tab)
{
	char	**dup;
	int		i;

	i = 0;
	dup = ft_tabnew(ft_tablen(tab));
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		++i;
	}
	return (dup);
}
