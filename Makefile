CFLAGS = -Werror -Wall -Wextra
NAME = push_swap
BONUS = checker

OBJS	=	atoi.o get_values.o linked_list.o linked_list_ops.o ops_utils.o stack_utils.o\
			operations1.o operations2.o sort_utils.o sort_arr.o push_swap.o valid.o
			

HEAD	= 	push_swap.h

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c $(HEAD)
	$(CC) -c $(CFLAGS) -o $@  $<

clean:
	echo "Remove .o  ..."
	rm -f $(OBJS)

fclean: clean
	echo "Remove lib ..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re