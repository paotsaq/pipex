HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
SRCS		= srcs/utils.c
TESTS		= tests/command_exists.c
AR			= ar -rcsv
NAME		= pipex
MAIN		= srcs/$(NAME).c
TEST_MAIN	= tests/main.c
OBJS		= ${SRCS:.c=.o}

all: $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

$(NAME): libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D DEBUG=0 $(SRCS) $(MAIN) -o $(NAME)

test: libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D DEBUG=1 $(TEST_MAIN) $(TESTS) $(SRCS) -o test

clean:
	rm ./$(NAME)
fclean:
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: clean all
