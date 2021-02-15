SRCS	= 	get_next_line.c 

OBJS	= ${SRCS:.c=.o}

NAME	= get_next_line.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
				ar rc  $(NAME) $(OBJS)
				ranlib $(NAME)

all:	$(NAME)

clean:
				$(RM) $(OBJS)
				make -sC ./get_next_line/ clean

fclean: clean
				$(RM) $(NAME)
				make -sC ./get_next_line/ clean

re:				fclean all

.PHONY: all fclean re