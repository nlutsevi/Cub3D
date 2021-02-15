LIBFT 	:= ./printf/libft/
PRINTF	:= ./printf/
GNL 	:= ./gnl/
CUB3D 	:= ./cub/

SRCS 	:= 	$(wildcard $(LIBFT)*.c) \
			$(wildcard $(GNL)*.c) \
			$(wildcard $(PRINTF)*.c) \
			$(wildcard $(CUB3D)*.c)


OBJS	:= $(SRCS:%.c=%.o)

NAME	:= cub3D

CC			:= gcc
MLXFLAGS 	:= -lmlx -framework OpenGL -framework AppKit -lm #-fsanitize=address -g3

CFLAGS		:= -Wall -Werror -Wextra -I. -o $(NAME)

RM		:= rm -f

all:		libft $(NAME)

$(NAME): ${OBJS}
			$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -L$(LIBFT)

$(%.o): $(%.c)
			$(CC) -c $^-o $@

libft:
			make -C $(LIBFT)


clean:
				$(RM) $(OBJS)
				make -C $(LIBFT) clean

fclean: clean
				$(RM) $(NAME)
				make -C $(LIBFT) fclean

re:				fclean all

.PHONY: all clean fclean re
