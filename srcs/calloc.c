/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:24:25 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/24 11:50:50 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	write(2, "6", 1);
	tmp = malloc(nmemb * size);
	ft_bzero(tmp, nmemb * size);
	write(2, "7", 1);
	return (tmp);
}
