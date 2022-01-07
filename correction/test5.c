#include "../includes/libft_malloc.h"

int	main(void)
{
	char *addr;

	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	addr = (char*)malloc(1024 * 1024 * 128);
	show_alloc_mem();
	free(addr);
	show_alloc_mem();
	return (0);
}
