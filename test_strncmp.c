#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "hel10", 5), 
		strncmp("hello", "hel10", 5)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "hel10", 3), 
		strncmp("hello", "hel10", 3)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "hel10", 0), 
		strncmp("hello", "hel10", 0)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "hello42", 7), 
		strncmp("hello", "hello42", 7)
	));

	return (MUNIT_OK);
}

static MunitResult test_edge(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_true(are_same_sign(
		ft_strncmp("", "", 0), 
		strncmp("", "", 0)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("", "", 3), 
		strncmp("", "", 3)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("hello", "", 3), 
		strncmp("hello", "", 3)
	));
	munit_assert_true(are_same_sign(
		ft_strncmp("", "hello", 7), 
		strncmp("", "hello", 7)
	));
	
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/edge", test_edge, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strncmp_suite = {
    "/strncmp", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};