LIBFT 	:= ./printf/libft/
PRINTF	:= ./printf/
GNL 	:= ./gnl/
MLX 	:= ./minilibx_opengl/
CUB3D 	:= ./cub/

SRCS 	:= 	$(wildcard $(LIBFT)*.c) \
			$(wildcard $(GNL)*.c) \
			$(wildcard $(PRINTF)*.c) \
			$(wildcard $(CUB3D)*.c)


OBJS	:= $(SRCS:%.c=%.o)

NAME	:= cub3D

CC			:= gcc
MLXFLAGS 	:= -framework OpenGL -framework AppKit

CFLAGS		:= -Wall -Werror -Wextra -o $(NAME)

RM		:= rm -f

all:		libft mlx $(NAME)

$(NAME): ${OBJS}
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(MLX)/libmlx.a $(MLXFLAGS)

$(%.o): $(%.c)
			$(CC) -c $^-o $@

libft:
			make -C $(LIBFT)

mlx:
			make -C $(MLX)

clean:
				$(RM) $(OBJS)
				make -C $(LIBFT) clean
				make -C $(MLX) clean

fclean: clean
				$(RM) $(NAME)
				make -C $(LIBFT) fclean
				make -C $(MLX) clean

re:				fclean all

.PHONY: all clean fclean re
