#ifndef TESTS_H
# define TESTS_H

# include "../munit/munit.h"
# include "../01-libft/libft.h"

int	are_same_sign(int i, int j);

extern MunitSuite charfn_suite;
extern MunitSuite strlcat_suite;
extern MunitSuite memcpy_suite;
extern MunitSuite memcmp_suite;
extern MunitSuite memchr_suite;
extern MunitSuite memmove_suite;
extern MunitSuite memset_suite;
extern MunitSuite strlen_suite;
extern MunitSuite atoi_suite;
extern MunitSuite strchr_suite;
extern MunitSuite strncmp_suite;
extern MunitSuite strlcpy_suite;
extern MunitSuite bzero_suite;
extern MunitSuite strnstr_suite;
extern MunitSuite calloc_suite;
extern MunitSuite substr_suite;

#endif