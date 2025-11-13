#include "tests.h"
#include <stdlib.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(
		ft_atoi("2147483647"), ==, 
		atoi("2147483647")
	);
	munit_assert_int(
		ft_atoi("1"), ==, 
		atoi("1")
	);
	munit_assert_int(
		ft_atoi("0"), ==, 
		atoi("0")
	);
	munit_assert_int(
		ft_atoi("-1"), ==, 
		atoi("-1")
	);
	munit_assert_int(
		ft_atoi("-2147483648"), ==, 
		atoi("-2147483648")
	);

	return (MUNIT_OK);
}

static MunitResult test_malformed(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(
		ft_atoi("0123"), ==, 
		atoi("0123")
	);
	munit_assert_int(
		ft_atoi("1042f12"), ==, 
		atoi("1042f12")
	);
	munit_assert_int(
		ft_atoi("x100"), ==, 
		atoi("x100")
	);
	munit_assert_int(
		ft_atoi("+230"), ==, 
		atoi("+230")
	);
	munit_assert_int(
		ft_atoi("--251"), ==, 
		atoi("--251")
	);
	munit_assert_int(
		ft_atoi("-+24121"), ==, 
		atoi("-+24121")
	);


	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/malformed", test_malformed, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite atoi_suite = {
    "/atoi", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};