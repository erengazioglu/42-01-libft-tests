#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char dst1[64] = "malloc";
	char dst2[64] = "malloc";
	char src[64] = "he";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 2),
		(char *) memcpy(dst2, src, 2)
	);

	return (MUNIT_OK);
}

static MunitResult test_len_zero(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char dst1[64] = "malloc";
	char dst2[64] = "malloc";
	char src[64] = "he";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 0),
		(char *) memcpy(dst2, src, 0)
	);

	return (MUNIT_OK);
}

static MunitResult test_dst_empty(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	
	char dst1[64] = "";
	char dst2[64] = "";
	char src[64] = "hello";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 2),
		(char *) memcpy(dst2, src, 2)
	);

	return (MUNIT_OK);
}

static MunitResult test_src_empty(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	
	char dst1[64] = "pompy";
	char dst2[64] = "pompy";
	char src[64] = "";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 12),
		(char *) memcpy(dst2, src, 12)
	);

	return (MUNIT_OK);
}

static MunitResult test_all_empty(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	
	char dst1[64] = "";
	char dst2[64] = "";
	char src[64] = "";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 12),
		(char *) memcpy(dst2, src, 12)
	);

	return (MUNIT_OK);
}

static MunitResult test_equal(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	
	char dst1[64] = "He\0y";
	char dst2[64] = "He\0y";
	char src[64] = "He\0y";

	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 0),
		(char *) memcpy(dst2, src, 0)
	);
	munit_assert_string_equal(
		(char *) ft_memcpy(dst1, src, 4),
		(char *) memcpy(dst2, src, 4)
	);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/len_zero", test_len_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/dst_empty", test_dst_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/src_empty", test_src_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/all_empty", test_all_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/equal", test_equal, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite memcpy_suite = {
    "/memcpy", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};