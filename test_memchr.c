#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char s1[64] = "kingkong";

	munit_assert_memory_equal(
		5,
		ft_memchr(s1, 'n', 8),
		memchr(s1, 'n', 8)
	);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite memchr_suite = {
    "/memchr", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};