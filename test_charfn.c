#include "tests.h"
#include <bsd/string.h>

static MunitResult test_isalnum(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_isalnum('A'), ==, 1);
	munit_assert_int(ft_isalnum('a'), ==, 1);
	munit_assert_int(ft_isalnum('0'), ==, 1);
	munit_assert_int(ft_isalnum('9'), ==, 1);
	munit_assert_int(ft_isalnum(' '), ==, 0);
	munit_assert_int(ft_isalnum('\0'), ==, 0);

	return (MUNIT_OK);
}

static MunitResult test_isalpha(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_isalpha('A'), ==, 1);
	munit_assert_int(ft_isalpha('a'), ==, 1);
	munit_assert_int(ft_isalpha('0'), ==, 0);
	munit_assert_int(ft_isalpha('9'), ==, 0);
	munit_assert_int(ft_isalpha(' '), ==, 0);
	munit_assert_int(ft_isalpha('\0'), ==, 0);

	return (MUNIT_OK);
}

static MunitResult test_isascii(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_isascii('A'), ==, 1);
	munit_assert_int(ft_isascii('a'), ==, 1);
	munit_assert_int(ft_isascii('0'), ==, 1);
	munit_assert_int(ft_isascii('9'), ==, 1);
	munit_assert_int(ft_isascii(' '), ==, 1);
	munit_assert_int(ft_isascii('\0'), ==, 1);

	return (MUNIT_OK);
}

static MunitResult test_isdigit(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_isdigit('A'), ==, 0);
	munit_assert_int(ft_isdigit('a'), ==, 0);
	munit_assert_int(ft_isdigit('0'), ==, 1);
	munit_assert_int(ft_isdigit('9'), ==, 1);
	munit_assert_int(ft_isdigit(' '), ==, 0);
	munit_assert_int(ft_isdigit('\0'), ==, 0);

	return (MUNIT_OK);
}

static MunitResult test_isprint(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_isprint('A'), ==, 1);
	munit_assert_int(ft_isprint('a'), ==, 1);
	munit_assert_int(ft_isprint('0'), ==, 1);
	munit_assert_int(ft_isprint('9'), ==, 1);
	munit_assert_int(ft_isprint(' '), ==, 1);
	munit_assert_int(ft_isprint('\0'), ==, 0);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/isalnum", test_isalnum, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/isalpha", test_isalpha, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/isascii", test_isascii, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/isdigit", test_isdigit, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/isprint", test_isprint, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite charfn_suite = {
    "/char-fn", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};