#include "tests.h"
#include <limits.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_itoa(1);
	char	*s2 = ft_itoa(20);
	char	*s3 = ft_itoa(54892);

	munit_assert_string_equal(s1, "1");
	munit_assert_string_equal(s2, "20");
	munit_assert_string_equal(s3, "54892");
	free(s1); free(s2); free(s3);

	return (MUNIT_OK);
}

static MunitResult test_zero(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_itoa(0);

	munit_assert_string_equal(s1, "0");
	free(s1);

	return (MUNIT_OK);
}

static MunitResult test_negative(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_itoa(-1);
	char	*s2 = ft_itoa(-20);
	char	*s3 = ft_itoa(-54892);

	munit_assert_string_equal(s1, "-1");
	munit_assert_string_equal(s2, "-20");
	munit_assert_string_equal(s3, "-54892");
	free(s1); free(s2); free(s3);

	return (MUNIT_OK);
}

static MunitResult test_limits(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_itoa(INT_MIN);
	char	*s2 = ft_itoa(INT_MAX);

	munit_assert_string_equal(s1, "-2147483648");
	munit_assert_string_equal(s2, "2147483647");
	free(s1); free(s2);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/positive", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/negative", test_negative, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/zero", test_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/limits", test_limits, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite itoa_suite = {
    "/itoa", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};