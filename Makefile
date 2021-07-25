HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
PS_MAIN		= srcs/main.c
SRCS		=

AR			= ar -rcsv
NAME		= pipex
OBJS		= ${SRCS:.c=.o}

all: $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

$(NAME): libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft $(SRCS) $(PS_MAIN) -o $(NAME)

checker: libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft $(CHECKER_SRC) $(SRCS) -o checker

clean:
	rm ./$(NAME)
fclean:
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: clean all

re_checker: clean_checker checker
