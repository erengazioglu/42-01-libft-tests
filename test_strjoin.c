#include "tests.h"

void	assert_strjoin(char *s1, char *s2, char **result, char *expect)
{
	char	*temp;

	temp = *result;
	*result = ft_strjoin(s1, s2);
	munit_assert_string_equal(*result, expect);
	if (temp)
		free(temp);
}

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char	*s1 = ft_strdup("");
	char	*s2 = ft_strdup("aglio ");
	char	*s3 = ft_strdup("olio ");
	char	*s4 = ft_strdup("peperoncino ");
	char	*result = NULL;

	assert_strjoin(s1, s1, &result, "");
	assert_strjoin(result, s2, &result, "aglio ");
	assert_strjoin(result, s3, &result, "aglio olio ");
	assert_strjoin(result, s4, &result, "aglio olio peperoncino ");
	assert_strjoin(result, s1, &result, "aglio olio peperoncino ");
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(result);
	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/all", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strjoin_suite = {
    "/strjoin", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};