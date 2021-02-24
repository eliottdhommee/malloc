#include "./includes/libft_malloc.h"
#include <stdio.h>
#include "libft/includes/libft.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 20000)
	{
	write(2, "pate", 4);
		addr = (char*)malloc(8);
		addr = memset(addr, 0, 8);
		printf("%p\n",addr);
		addr = realloc(addr, 16);
		addr = memset(addr, 0, 16);
		printf("%p\n",addr);
		addr[0] = 42;
		i++;
	}
	return(0);
}
