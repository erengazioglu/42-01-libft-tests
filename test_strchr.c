#include "tests.h"
#include <bsd/string.h>

static MunitResult test_strchr(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char	s1[64] = "hello";
	char	s2[64] = "yo";
	char	s3[64] = "";
	char	s4[64] = "hey\0I'm hidden";

	munit_assert_ptr_equal(
		ft_strchr(s1, 'l'), strchr(s1, 'l')
	);
	munit_assert_ptr_equal(
		ft_strchr(s1, 'z'), strchr(s1, 'z')
	);
	munit_assert_ptr_equal(
		ft_strchr(s1, 300), strchr(s1, 300)
	);
	munit_assert_ptr_equal(
		ft_strchr(s2, 'y'), strchr(s2, 'y')
	);
	munit_assert_ptr_equal(
		ft_strchr(s3, '\t'), strchr(s3, '\t')
	);
	munit_assert_ptr_equal(
		ft_strchr(s3, '\0'), strchr(s3, '\0')
	);
	munit_assert_ptr_equal(
		ft_strchr(s4, '\0'), strchr(s4, '\0')
	);
	munit_assert_ptr_equal(
		ft_strchr(s4, 'h'), strchr(s4, 'h')
	);

	return (MUNIT_OK);
}

static MunitResult test_strrchr(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char	s1[64] = "hello";
	char	s2[64] = "yo";
	char	s3[64] = "";
	char	s4[64] = "hey\0I'm hidden";

	munit_assert_ptr_equal(
		ft_strrchr(s1, 'l'), strrchr(s1, 'l')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s1, 'z'), strrchr(s1, 'z')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s1, 300), strrchr(s1, 300)
	);
	munit_assert_ptr_equal(
		ft_strrchr(s2, 'y'), strrchr(s2, 'y')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s3, '\t'), strrchr(s3, '\t')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s3, '\0'), strrchr(s3, '\0')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s4, '\0'), strrchr(s4, '\0')
	);
	munit_assert_ptr_equal(
		ft_strrchr(s4, 'h'), strrchr(s4, 'h')
	);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/left", test_strchr, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/right", test_strrchr, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strchr_suite = {
    "/strchr", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};