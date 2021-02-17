/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:24:25 by edhommee          #+#    #+#             */
/*   Updated: 2021/02/17 10:12:27 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = malloc(nmemb * size);
	ft_bzero(tmp, nmemb * size);
	return(tmp);
}
