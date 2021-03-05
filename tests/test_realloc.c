#include <libft_malloc.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/types.h>

Test(Realloc, base) {
	char *p;
	char *tp;

	tp = ft_malloc(200);
	cr_assert_not_null(p);
	p = ft_realloc(p, 201);
	cr_assert_neq(p, tp);
}
