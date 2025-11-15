#include "tests.h"

void	assert_substr(char* str, unsigned int start, size_t len, char *expect)
{
	char	*new = ft_substr(str, start, len);
	if (!new)
		munit_error("ft_substr returned NULL (malloc failed)");

	munit_assert_string_equal(new, expect);
	free(new);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	assert_substr("coerente", 0, 8, "coerente");
	assert_substr("coerente", 2, 4, "eren");

	return (MUNIT_OK);
}

static MunitResult test_empty(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	assert_substr("", 0, 0, "");
	assert_substr("", 2, 0, "");
	assert_substr("", 0, 4, "");
	assert_substr("", 2, 4, "");

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/empty", test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite substr_suite = {
    "/substr", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};