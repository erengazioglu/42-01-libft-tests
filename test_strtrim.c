#include "tests.h"

void	assert_strtrim(char *s1, char *set, char **result, char *expect)
{
	char	*temp;

	temp = *result;
	*result = ft_strtrim(s1, set);
	munit_assert_string_equal(*result, expect);
	if (temp)
		free(temp);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_strdup("13 39184 aglio 39823 ");
	char	*s2 = ft_strdup("olio ");
	char	*s3 = ft_strdup(" peperoncino");
	char	*s4 = ft_strdup("con un po' di grana padano");
	char	*s5 = ft_strdup("");
	char	*result = NULL;

	assert_strtrim(s1, "0123456789 ", &result, "aglio");
	assert_strtrim(s2, " ", &result, "olio");
	assert_strtrim(s3, " ", &result, "peperoncino");
	assert_strtrim(s4, " ", &result, "con un po' di grana padano");
	assert_strtrim(s5, "", &result, "");
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(s5);
	free(result);
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strtrim_suite = {
    "/strtrim", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};