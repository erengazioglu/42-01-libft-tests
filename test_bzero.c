#include "tests.h"
#include <bsd/string.h>

void	assert_bzero(void *ptr1, void *ptr2, int i, size_t size)
{
	ft_bzero(ptr1, i);
	bzero(ptr2, i);
	munit_assert_memory_equal(size, ptr1, ptr2);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	int		int1[20] = {1, 3, 2, 30, 349};
	int		int2[20] = {1, 3, 2, 30, 349};
	char	char1[20] = "hello world";
	char	char2[20] = "hello world";

	assert_bzero(int1, int2, 0, 20);
	assert_bzero(int1, int2, 10, 20);
	assert_bzero(int1, int2, 20, 20);
	assert_bzero(char1, char2, 0, 20);
	assert_bzero(char1, char2, 10, 20);
	assert_bzero(char1, char2, 20, 20);
	
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite bzero_suite = {
    "/bzero", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};