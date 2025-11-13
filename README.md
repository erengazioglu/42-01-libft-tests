# 42cursus — 01 Libft

## How to use

- Clone this repo into the same directory as where your Libft is.
- Also `git clone https://github.com/nemequ/munit.git` (the c framework used for unit testing).
- Run `make`.

By default it looks for `../01-libft` and `../munit/munit.c`, but you can modify the following lines in the Makefile to suit your folder structure:
- `@make -C ../01-libft` (in the "all" rule)
- `../munit/munit.c` (defined in the "SRCS" variable)

## Troubleshooting

If you're getting the following error:  
```
(...) fatal error: bsd/string.h: No such file or directory
    2 | #include <bsd/string.h>
```
It means you don't have bsd installed on your system (are you running a WSL maybe?).  
In that case, you simply have to install bsd running `sudo apt install libbsd-dev`.