#include "../includes/libft_malloc.h"
#include <stdio.h>
#include "../libft/includes/libft.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	printf("test");
	while(i < 10)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return(0);
}
