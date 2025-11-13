# 42cursus — 01 Libft

## How to use

- Clone this repo into the same directory as where your Libft is.
- Also `git clone https://github.com/nemequ/munit.git` (the c framework used for unit testing).
- Run `make`.

By default it looks for `../01-libft` and `../munit/munit.c`, but you can modify the following lines in the Makefile to suit your folder structure:
- `@make -C ../01-libft` (in the "all" rule)
- `../munit/munit.c` (defined in the "SRCS" variable)

## Checklist for adding new tests

- I copy one of the existing `test_*.c` files.
- I write as many test functions as I need, with the signature `static MunitResult test_<name>(const MunitParameter params[], void* data)`.
- I register them inside `static MunitTest tests[]` (i.e. `{ "/<test_name>", <fn_name>, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },`).
- I rename the test suite: `MunitSuite <name>_suite = { "/<suite_name>", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };`.
- I add the test suite into `tests.h` as follows: `extern MunitSuite <name>_suite`.
- I add the same suite to `main.c`.

Then `make` & enjoy!

## Troubleshooting

If you're getting the following error:  
```
(...) fatal error: bsd/string.h: No such file or directory
    2 | #include <bsd/string.h>
```
It means you don't have bsd installed on your system (are you running a WSL maybe?).  
In that case, you simply have to install bsd running either: 
- `sudo apt install libbsd-dev` (linux)
- `brew install libbsd` (mac)