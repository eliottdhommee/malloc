/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:17:20 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:10:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>
#include <libft.h>

t_list		*ft_tabtolst(char **tab)
{
	t_list		*new_list;
	int			i;

	i = 0;
	new_list = NULL;
	while (tab[i])
	{
		ft_lstaddback(&new_list, (void*)ft_strdup(tab[i]));
		i++;
	}
	return (new_list);
}
