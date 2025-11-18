#include "tests.h"
#include "../munit/munit.h"

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	MunitSuite libc_suites[] = {
		atoi_suite,
		bzero_suite,
		calloc_suite,
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
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};
	MunitSuite extra_suites[] = {
		substr_suite,
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};
	MunitSuite bonus_suites[] = {
		lstadd_back_suite,
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};
	MunitSuite all[] = {
		{ "/libc", NULL, libc_suites, 1, MUNIT_SUITE_OPTION_NONE },
		{ "/extra", NULL, extra_suites, 1, MUNIT_SUITE_OPTION_NONE },
		{ "/bonus", NULL, bonus_suites, 1, MUNIT_SUITE_OPTION_NONE },
		{ NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
	};


	const MunitSuite main_suite = {
		"/libft", NULL, (MunitSuite *) all, 1, MUNIT_SUITE_OPTION_NONE
	};
	return munit_suite_main(&main_suite, NULL, argc, argv);
}