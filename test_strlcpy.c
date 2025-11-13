#include "tests.h"
#include <bsd/string.h>

void	assert_strlcpy(char *dst1, char *dst2, char *src, size_t i)
{
	munit_assert_int(
		ft_strlcpy(dst1, src, i), ==, 
		strlcpy(dst2, src, i)
	);
	munit_assert_string_equal(dst1, dst2);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char dst1[64] = "";
	char dst2[64] = "";

	assert_strlcpy(dst1, dst2, "", 0);
	assert_strlcpy(dst1, dst2, "", 64);
	assert_strlcpy(dst1, dst2, "what", 2);
	assert_strlcpy(dst1, dst2, "what", 64);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strlcpy_suite = {
    "/strlcpy", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};