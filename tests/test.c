#include "../includes/libft_malloc.h"
#include <stdio.h>
#include "../libft/includes/libft.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 20000)
	{
		addr = (char*)malloc(5000);
		addr = memset(addr, 0, 5000);
		dprintf(2, "%p\n",addr);
		realloc(addr, 6000);
		addr[0] = 42;
		i++;
	}
	return(0);
}
/*
#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr1;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
	return (0);
}
*/
