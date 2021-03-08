#include <libft_malloc.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/types.h>

Test(Malloc, alignement) {
	char *p;

	p = ft_malloc(200);
	cr_assert(((unsigned long)p & 15) ==  0, "test alignement %lu\n", (unsigned long)p & 15);
}

Test(Malloc, some_malloc) {
	char *tmp = ft_malloc(1024);
	char *tmp1 = ft_malloc(0);
	char *tmp2 = ft_malloc(1024 * 32);
	char *tmp3 = ft_malloc(1024 * 1024);
	char *tmp4 = ft_malloc(1024 * 1024 * 16);
	char *tmp5 = ft_malloc(1024 * 1024 * 128);
	char *tmp6 = ft_malloc(1);

	cr_assert_not_null(tmp);
	cr_assert_null(tmp1);
	cr_assert_not_null(tmp2);
	cr_assert_not_null(tmp3);
	cr_assert_not_null(tmp4);
	cr_assert_not_null(tmp5);
	cr_assert_not_null(tmp6);
}

Test(Malloc, tiny_lot) {
	int i;
	char *tiny;
	int size;

	i = 1;
	size = 4035;
	while(i < 1)
	{
		//printf("%d\n",i);
		tiny= (char*)ft_malloc(i);
		cr_assert_not_null(tiny);
		tiny = memset(tiny, 0, i);
		i++;
	}
	cr_assert_not_null(tiny);
}

Test(Malloc, small_lot) {
	int i;
	char *small;
	int size;
	t_page *tmp;

	i = 1;
	size  = 1000;
	while(i < 2000)
	{
		small= (char*)ft_malloc(i);
		small= memset(small, 0, i);
		small= memset(small, 0, i);
		tmp = (t_page*)((char*)small - sizeof(t_page));
		cr_expect_geq(tmp->size, (size_t)(i + sizeof(t_page)), "%zu > %d\n", tmp->size, i);
		i++;
	}
	cr_assert_not_null(small, "not null");
}

Test(Malloc, large_lot) {
	int i;
	char *large;
	int size;

	size = 10000;
	i = 0;
	while(i < 1)
	{
		ft_free(large);
		large = (char*)ft_malloc(size);
		large = memset(large, 0, size);
		i++;
	}
	cr_assert_not_null(large);
}
