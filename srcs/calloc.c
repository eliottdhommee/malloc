/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:24:25 by edhommee          #+#    #+#             */
/*   Updated: 2021/03/03 10:42:48 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	//ft_putstr_fd("calloc : ", 2);
	if (nmemb == 0 || size == 0)
		return (NULL);
	tmp = malloc(nmemb * size);
	ft_bzero(tmp, nmemb * size);
	//print_address_hex(tmp);
	return (tmp);
}
