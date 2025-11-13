CC		= cc
CFLAGS	= --no-warnings -std=c11
NAME	= run

# ---
# This is for cross-platform compatibility
LDFLAGS =
LDLIBS	=
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    LDLIBS += -lbsd
else ifeq ($(UNAME_S),Darwin)
	BREW_PREFIX := $(shell brew --prefix 2>/dev/null)
    ifneq ($(BREW_PREFIX),)
        CFLAGS  += -I$(BREW_PREFIX)/include
        LDFLAGS += -L$(BREW_PREFIX)/lib
        LDLIBS  += -lbsd
    endif
endif

# ---
# Source files
INC		= tests.h
SRCS	= \
		../munit/munit.c \
		main.c \
		$(wildcard test_*.c) \
		../01-libft/libft.a

# ---
# Rules
all		:
	@make -C ../01-libft
	@make $(NAME)
	@echo
	@./$(NAME)

$(NAME)	: $(SRCS) $(INC)
	@$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

fclean	:
	rm -f run

re		: fclean all