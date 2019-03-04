/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:50:45 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/12 13:39:25 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabnew(int size)
{
	char		**new;

	if (!(new = ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	return (new);
}
