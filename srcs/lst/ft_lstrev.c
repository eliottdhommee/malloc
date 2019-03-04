/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:16:34 by edhommee          #+#    #+#             */
/*   Updated: 2018/03/09 21:09:41 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>
#include <libft.h>

void		ft_lstrev(t_list **begin_list)
{
	int			size;
	int			i;

	i = 1;
	size = ft_lstsize(*begin_list) + 1;
	while (i <= size / 2)
	{
		ft_swap_star(&(ft_lstat(*begin_list, i)->data),
				&(ft_lstat(*begin_list, size - i)->data));
		i++;
	}
}
