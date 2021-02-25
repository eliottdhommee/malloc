#include "./includes/libft_malloc.h"
#include <stdio.h>
#include "libft/includes/libft.h"

/*int main()
{
	int i;
	char *addr;

	i = 0;
	while(i < 20000)
	{
	write(2, "pate", 4);
		addr = (char*)malloc(8);
		addr = memset(addr, 0, 8);
		dprintf(2, "%p\n",addr);
		addr = realloc(addr, 16);
		addr = memset(addr, 0, 16);
		dprintf(2, "%p\n",addr);
		addr[0] = 42;
		i++;
	}
	return(0);
}*/
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
