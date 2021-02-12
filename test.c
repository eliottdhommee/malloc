#include "./includes/libft_malloc.h"
#include <stdio.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 1024)
	{
		addr = (char*)malloc(1024);
		printf("test\n");
		addr[0] = 42;
		i++;
	}
	return(0);
}
