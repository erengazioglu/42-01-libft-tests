#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char s1[64] = "";
	char s2[64] = "";
	// char s3[64] = "he";

	munit_assert_memory_equal(
		64,
		ft_memset(s1, 'a', 0),
		memset(s2, 'a', 0)
	);
	munit_assert_memory_equal(
		64,
		ft_memset(s1, 'a', 4),
		memset(s2, 'a', 4)
	);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite memset_suite = {
    "/memset", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};