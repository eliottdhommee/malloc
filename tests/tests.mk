ifndef TESTS_MK
	TESTS_MK = 1

TEST_NAME	= unit_test
T			= tests/
TESTS		= $Ttest_malloc.c
TEST_LIB	= -L/Users/edhommee/.brew/Cellar/criterion/2.3.3/lib -lcriterion
TEST_INC	= -I/Users/edhommee/.brew/Cellar/criterion/2.3.3/include

test:$(NAME)
	gcc $(TESTS) $(NAME) $(INCLUDES) $(TEST_LIB) $(TEST_INC) -o $(TEST_NAME)
	./$(TEST_NAME)

endif
