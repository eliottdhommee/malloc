/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:58:52 by edhommee          #+#    #+#             */
/*   Updated: 2022/01/07 12:17:38 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>
#include <stdint.h>

char		hex_digit(int v) {
	if (v >= 0 && v < 10)
		return '0' + v;
	else
		return 'a' + v - 10;
}

void		print_address_hex(void* p0) {
	int i;
	uintptr_t p = (uintptr_t)p0;

	write_char('0');
	write_char('x');
	for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4)
	{
		write_char(hex_digit((p >> i) & 0xf));
	}
}

void 		show_type(t_page *page)
{
	t_page	*tmp;

	tmp = page;
	while(tmp)
	{
		if(tmp->free == FALSE)
		{
			print_address_hex((char*)tmp + sizeof(t_page));
			ft_putstr(" - ");
			print_address_hex((char*)tmp + sizeof(t_page) + tmp->size);
			ft_putstr(" : ");
			ft_putnbr(tmp->size);
			ft_putstr("octets");
			write_char('\n');
		}
		tmp = tmp->next;
	}
}

void		show_alloc_mem(void)
{
	t_page	*tmp;

	tmp = stock_roots(0);
	ft_putstr("TINY: ");
	print_address_hex(tmp);
	write_char('\n');
	show_type(tmp);
	tmp = stock_roots(SMALL_MALLOC);
	ft_putstr("SMALL: ");
	print_address_hex(tmp);
	write_char('\n');
	show_type(tmp);
	tmp = stock_roots(SMALL_MALLOC + 1);
	ft_putstr("LARGE: ");
	print_address_hex(tmp);
	write_char('\n');
	show_type(tmp);
}
