#include "tests.h"

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	
	
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite lstadd_back_suite = {
    "/lstadd_back", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};