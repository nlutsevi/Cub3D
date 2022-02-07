GNL 	:= ./gnl/
MLX 	:= ./minilibx_opengl/
CUB3D 	:= ./cub/

SRCS 	:= 	$(wildcard $(GNL)*.c) \
			$(wildcard $(CUB3D)*.c)

OBJS	:= $(SRCS:%.c=%.o)

NAME	:= cub3D

CC			:= gcc
MLXFLAGS 	:= -framework OpenGL -framework AppKit

CFLAGS		:= -Wall -Werror -Wextra -o $(NAME)

RM		:= rm -f

all:		mlx $(NAME)

$(NAME): ${OBJS}
			$(CC) $(CFLAGS) $(OBJS) $(MLX)/libmlx.a $(MLXFLAGS)

$(%.o): $(%.c)
			$(CC) -c $^-o $@

mlx:
			make -C $(MLX)

clean:
				$(RM) $(OBJS)
				make -C $(MLX) clean

fclean: clean
				$(RM) $(NAME)
				make -C $(MLX) clean

re:				fclean all

.PHONY: all clean fclean re
