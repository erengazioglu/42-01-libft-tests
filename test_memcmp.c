#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char s1[64] = "frown";
	char s2[64] = "frog";

	munit_assert_int(
		ft_memcmp(s1, s2, 3),
		==,
		memcmp(s1, s2, 3)
	);
	munit_assert_int(
		ft_memcmp(s1, s2, 5),
		==,
		memcmp(s1, s2, 5)
	);
	munit_assert_int(
		ft_memcmp(s1, s2, 0),
		==,
		memcmp(s1, s2, 0)
	);

	return (MUNIT_OK);
}

static MunitResult test_null_char(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = "atoms\0\0\0\0";
	char	*s2 = "atoms\0abc";

	munit_assert_true(
		are_same_sign(ft_memcmp(s1, s2, 8), memcmp(s1, s2, 8))
	);
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/null_char", test_null_char, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite memcmp_suite = {
    "/memcmp", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};