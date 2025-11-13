CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c11
NAME	= run

INC		= tests.h
SRCS	= \
		../munit/munit.c \
		main.c \
		$(wildcard test_*.c) \
		../01-libft/libft.a

all		:
	@make -C ../01-libft
	@make $(NAME)
	@echo
	@./$(NAME)

$(NAME)	: $(SRCS) $(INC)
	@$(CC) $(CFLAGS) $(SRCS) -lbsd -o $(NAME)

fclean	:
	rm -f run

re		: fclean all