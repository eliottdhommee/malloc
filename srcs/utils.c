/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:32:17 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:17:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void		ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putstr(const char *s)
{
	ft_putstr_fd(s, 1);
}

void		write_char(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	char	*tmp;

	tmp = (char*)str;
	while (*str)
		str++;
	return (str - tmp);
}

void	*ft_memcpy2(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write_char('-');
		write_char('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		write_char('-');
		nb = -nb;
	}
	if (nb <= 9)
	{
		write_char(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		write_char('0' + (nb % 10));
	}
}

