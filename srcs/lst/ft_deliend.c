/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deliend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:34:23 by edhommee          #+#    #+#             */
/*   Updated: 2017/12/12 17:36:45 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblst.h>

void		ft_delie(t_list **list, unsigned int i, void (*del)(void*))
{
	ft_deli(list, ft_lstsize(*list) - i, del);
}
