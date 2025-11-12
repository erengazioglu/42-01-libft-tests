#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char text1[64] = "hello bro why u do dis";
	char text2[64] = "hello bro why u do dis";
	char *src1 = text1;
	char *src2 = text2;
	char *dest1 = text1 + 6;
	char *dest2 = text2 + 6;

	munit_assert_memory_equal(
		20,
		ft_memmove(dest1, src1, 9),
		memmove(dest2, src2, 9)
	);

	return (MUNIT_OK);
}

static MunitResult test_inverse(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char text1[64] = "hello bro why u do dis";
	char text2[64] = "hello bro why u do dis";
	char *src1 = text1 + 6;
	char *src2 = text2 + 6;
	char *dest1 = text1;
	char *dest2 = text2;

	munit_assert_memory_equal(
		20,
		ft_memmove(dest1, src1, 9),
		memmove(dest2, src2, 9)
	);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/inverse", test_inverse, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite memmove_suite = {
    "/memmove", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};