/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 09:59:01 by edhommee          #+#    #+#             */
/*   Updated: 2017/08/22 14:10:41 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_tabdel(char ***tab)
{
	int		i;
	char	**tmp;

	tmp = *tab;
	i = 0;
	if (tmp)
	{
		while (tmp[i])
			ft_strdel(&tmp[i++]);
		ft_memdel((void *)tab);
	}
}
