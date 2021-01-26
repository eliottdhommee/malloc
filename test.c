#include "./includes/libft_malloc.h"
#include <stdio.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 2024)
	{
		addr = (char*)ft_malloc(1024);
		addr[0] = 42;
		printf("variable A is at address: %p\n", (void*)addr);
		i++;
	}
	return(0);
}
