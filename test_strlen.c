#include "tests.h"
#include <bsd/string.h>

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	munit_assert_int(ft_strlen("kingkong"), ==, 8);
	munit_assert_int(ft_strlen("kingkong\0dingdong"), ==, 8);
	munit_assert_int(ft_strlen(""), ==, 0);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strlen_suite = {
    "/strlen", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};