#include "tests.h"
#include <bsd/string.h>

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
#define		STRING_4	"phrase differente pour le test"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"

static MunitResult test_basic(const MunitParameter params[], void* data)
{
	(void) params; (void) data;

	char s1[20] = "hello";
	int result = ft_strlcat(s1, " sup", 12);
	munit_assert_string_equal(s1, "hello sup");
	munit_assert_int(result, ==, 9);

	char	s2[4] 	= "";
	char	s3[4] 	= "";
	int		r2 		= ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	int		r3 		= ft_strlcat(s3, "thx to ntoniolo for this test !", 4);

	munit_assert_string_equal(s2, s3);
	munit_assert_int(r2, ==, r3);

	char	*src = "the cake is a lie !\0I'm hidden lol\r\n";
	char	s4[256]	= "there is no stars in the sky";
	char	s5[256]	= "there is no stars in the sky";

			// char	buff1[0xF00] = STRING_2;
			// char	buff2[0xF00] = STRING_2;
			// size_t	max = strlen(STRING_1) + 4;

			// size_t	r1 = strlcat(buff1, str, max);
			// size_t	r2 = ft_strlcat(buff2, str, max);
			// SET_DIFF_INT((int)r1, (int)r2);
			// ASSERT_RETURN_VALUE(r1, r2);

	int		r4		= strlcat(s4, src, strlen(src) + 4);
	int		r5		= ft_strlcat(s5, src, strlen(src) + 4);

	munit_assert_string_equal(s4, s5);
	munit_assert_int(r4, ==, r5);	

	return (MUNIT_OK);
}

static MunitResult test_empty_src(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char str[20] = "hello";
	int result = ft_strlcat(str, "", 20);

	munit_assert_string_equal(str, "hello");
	munit_assert_int(result, ==, 5);
	return (MUNIT_OK);
}

static MunitResult test_empty_dst(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char str[20] = "";
	int result = ft_strlcat(str, "hey", 4);

	munit_assert_string_equal(str, "hey");
	munit_assert_int(result, ==, 3);
	return (MUNIT_OK);
}

static MunitResult test_empty_both(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char str[20] = "";
	int result = ft_strlcat(str, "", 5);

	munit_assert_string_equal(str, "");
	munit_assert_int(result, ==, 0);
	return (MUNIT_OK);
}

static MunitResult test_dstsize_short(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	
	char str1[20] = "hello";
	int result1 = ft_strlcat(str1, " sup", 5);
	munit_assert_string_equal(str1, "hello");
	munit_assert_int(result1, ==, 9);
	
	char str2[20] = "hello";
	int result2 = ft_strlcat(str2, " how are you", 8);
	munit_assert_string_equal(str2, "hello h");
	munit_assert_int(result2, ==, 17);

	char str3[20] = "rrrrrrrrrrrrrrr";
	char str4[20] = "rrrrrrrrrrrrrrr";
	int result3 = ft_strlcat(str3, "lorem ipsum dolor sit amet", 5);
	int result4 = strlcat(str4, "lorem ipsum dolor sit amet", 5);
	// printf("\nft_strlen -> %s\n", str3);
	// printf("strlen -> %s\n", str4);
	munit_assert_string_equal(str3, str4);
	munit_assert_int(result3, ==, result4);

	return (MUNIT_OK);
}

static MunitResult test_dstsize_zero(const MunitParameter params[], void* data)
{
	(void) params; (void) data;
	char str1[20] = "hello";
	char str2[20] = "hello";
	
	int result1 = ft_strlcat(str1, " sup", 0);
	int result2 = strlcat(str2, " sup", 0);
	munit_assert_string_equal(str1, str2);
	munit_assert_int(result1, ==, result2);

	char *str3 = NULL;
	char *str4 = NULL;
	result1 = ft_strlcat(str3, " sup", 0);
	result2 = strlcat(str4, " sup", 0);
	munit_assert_null(str3);
	munit_assert_int(result1, ==, result2);

	return (MUNIT_OK);
}

static MunitTest tests[] = {
	{ "/basic", test_basic, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/empty_src", test_empty_src, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/empty_dst", test_empty_dst, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/empty_both", test_empty_both, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/dstsize_short", test_dstsize_short, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ "/dstsize_zero", test_dstsize_zero, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// this will be used in main.c
MunitSuite strlcat_suite = {
    "/strlcat", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};