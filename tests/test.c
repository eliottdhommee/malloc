#include "../includes/libft_malloc.h"
#include <stdio.h>
#include "../libft/includes/libft.h"

/*
int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return(0);
}
*/
#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;

	addr = (char*)malloc(16);
	free(NULL);
	free((void*)addr + 5);
	if(realloc((void*)addr + 5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}
