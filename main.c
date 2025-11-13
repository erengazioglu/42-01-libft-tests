#include "tests.h"
#include "../munit/munit.h"

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	MunitSuite all_suites[] = {
		charfn_suite,
		strlcat_suite,
		memcpy_suite,
		memcmp_suite,
		memchr_suite,
		memmove_suite,
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};
	const MunitSuite main_suite = {
		"/all", NULL, (MunitSuite *) all_suites, 1, MUNIT_SUITE_OPTION_NONE
	};
	return munit_suite_main(&main_suite, NULL, argc, argv);
}