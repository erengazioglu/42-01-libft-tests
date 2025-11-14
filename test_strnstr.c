#include "tests.h"
#include <bsd/string.h>

void	assert_strnstr(char *haystack, char *needle, size_t n)
{
	munit_assert_ptr_equal(
		ft_strnstr(haystack, needle, n),
		strnstr(haystack, needle, n)
	);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char str[64] = "start my friend\0hidden stuff";

	assert_strnstr(str, "end", 64);
	assert_strnstr(str, "start", 64);
	assert_strnstr(str, "my", 64);
	assert_strnstr(str, "hidden", 64);
	assert_strnstr(str, "I don't exist", 64);

	return (MUNIT_OK);
}

static MunitResult test_empty(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char str1[64] = "";
	char str2[64] = "hello";

	assert_strnstr(str1, "end", 0);
	assert_strnstr(str2, "", 5);
	assert_strnstr(str1, "", 0);

	return (MUNIT_OK);
}

static MunitResult test_null(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char str1[64] = "";
	char str2[64] = "hello";
	char str3[64] = "hello\0hidden stuff";
	char *str4 = NULL;

	assert_strnstr(str1, "\0", 0);
	assert_strnstr(str1, "\0", 64);
	assert_strnstr(str2, "\0", 64);
	assert_strnstr(str3, "hidden", 64);
	assert_strnstr(str4, "hidden", 0);

	return (MUNIT_OK);
}

static MunitResult test_beyond_len(const MunitParameter params[], void *data)
{
	// test inspired from alelievr/libft-unit-test
	char	*s1 = "rampapapam";
	char	*s2 = "pam";

	assert_strnstr(s1, s2, 8);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/empty", test_empty, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/null", test_null, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/beyond_len", test_beyond_len, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strnstr_suite = {
    "/strnstr", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};