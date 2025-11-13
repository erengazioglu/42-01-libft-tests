#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "hel10", 5), 
		strncmp("hello", "hel10", 5)
	));

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strncmp_suite = {
    "/strncmp", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};