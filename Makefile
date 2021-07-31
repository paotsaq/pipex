HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
SRCS		= srcs/utils.c \
			  srcs/execute_command.c \
			  srcs/commands_handler.c \
			  srcs/file_handler.c

DEFAULT		= srcs/check_number_arguments.c

BONUS		= srcs/check_number_arguments_bonus.c \
			  srcs/heredoc_bonus.c

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
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D BONUS=0 $(SRCS) $(DEFAULT) $(MAIN) -o $(NAME)

bonus: libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft -D BONUS=1 $(SRCS) $(BONUS) $(MAIN) -o $(NAME)

clean:
	rm ./$(NAME)
fclean:
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: clean all
