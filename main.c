#include "tests.h"
#include "../munit/munit.h"

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	MunitSuite all_suites[] = {
		atoi_suite,
		charfn_suite,
		memcpy_suite,
		memcmp_suite,
		memchr_suite,
		memmove_suite,
		memset_suite,
		strlen_suite,
		strncmp_suite,
		strchr_suite,
		strnstr_suite,
		strlcpy_suite,
		strlcat_suite,
		bzero_suite,
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};
	const MunitSuite main_suite = {
		"/all", NULL, (MunitSuite *) all_suites, 1, MUNIT_SUITE_OPTION_NONE
	};
	return munit_suite_main(&main_suite, NULL, argc, argv);
}