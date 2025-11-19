#include "tests.h"
#include <limits.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_memory_equal(
		16,
		ft_calloc(16, sizeof(char)),
		calloc(16, sizeof(char))
	);
	munit_assert_memory_equal(
		0,
		ft_calloc(0, sizeof(char)),
		calloc(0, sizeof(char))
	);

	return (MUNIT_OK);
}

static MunitResult test_malloc_failure(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_null(
		ft_calloc(-1, 1)
	);
	munit_assert_null(
		ft_calloc(-5, -5)
	);
	munit_assert_null(
		ft_calloc(SIZE_MAX, SIZE_MAX)
	);


	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/malloc_failure", test_malloc_failure, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite calloc_suite = {
    "/calloc", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};