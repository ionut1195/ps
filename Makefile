CFLAGS = -Werror -Wall -Wextra
NAME = push_swap
BONUS = checker

OBJS	=	atoi.o get_values.o linked_list.o ll_ops.o\
			operations.o sort_utils.o sort.o total_ops.o
			

HEAD	= 	push_swap.h

all : $(NAME)

bonus : $(BONUS)

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

.PHONY: all clean fclean re bonus