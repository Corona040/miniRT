NAME = tester

SRCS = test.c							\
	   unit_tests/unit_isalpha.c		\
	   unit_tests/unit_isdigit.c		\
	   unit_tests/unit_isalnum.c		\
	   unit_tests/unit_isascii.c		\
	   unit_tests/unit_isprint.c		\
	   unit_tests/unit_toupper.c 		\
	   unit_tests/unit_tolower.c 		\
	   unit_tests/unit_strlen.c			\
	   unit_tests/unit_strchr.c			\
	   unit_tests/unit_strrchr.c		\
	   unit_tests/unit_strncmp.c		\
	   unit_tests/unit_memcmp.c			\
	   unit_tests/unit_memset.c			\
	   unit_tests/unit_memchr.c			\
	   unit_tests/unit_bzero.c			\
	   unit_tests/unit_memcpy.c			\
	   unit_tests/unit_memmove.c		\
	   unit_tests/unit_strnstr.c		\
	   unit_tests/unit_strlcpy.c		\
	   unit_tests/unit_strlcat.c		\
	   unit_tests/unit_atoi.c			\
	   unit_tests/unit_calloc.c			\
	   unit_tests/unit_strdup.c			\
	   unit_tests/unit_substr.c			\
	   unit_tests/unit_strjoin.c 		\
	   unit_tests/unit_strtrim.c 		\
	   unit_tests/unit_split.c			\
	   unit_tests/unit_itoa.c			\
	   unit_tests/unit_strmapi.c 		\
	   unit_tests/unit_striteri.c		\
	   unit_tests/unit_putchar_fd.c		\
	   unit_tests/unit_putstr_fd.c		\
	   unit_tests/unit_putendl_fd.c		\
	   unit_tests/unit_putnbr_fd.c		\
	   unit_tests/unit_lstnew.c			\
	   unit_tests/unit_lstadd_front.c	\
	   unit_tests/unit_lstsize.c		\
	   unit_tests/unit_lstlast.c		\
	   unit_tests/unit_lstadd_back.c	\
	   unit_tests/unit_lstdelone.c		\
	   unit_tests/unit_lstclear.c		\
	   unit_tests/unit_lstiter.c		\
	   unit_tests/unit_lstmap.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -g

LDLIBS = -lft -lbsd -lmalloc_hook

LDFLAGS = -L.. -L/usr/lib/x86_64-linux-gnu -L. -Wl,-rpath=.

MALLOC = malloc_hook.c

LMALLOC = lib$(MALLOC:.c=.so)

all: $(NAME)

$(NAME): $(OBJS) $(LMALLOC)
	make -C ..
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(LDLIBS) $(LDFLAGS)

$(LMALLOC): $(MALLOC)
	$(CC) -shared -o $(LMALLOC) -fPIC $(MALLOC)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

test: all
	./$(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ..

fclean: clean
	rm -rf $(NAME) $(LMALLOC)
	make fclean -C ..

re: fclean all

.PHONY: all clean fclean re test
