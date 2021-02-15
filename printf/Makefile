SRCS	= 	flag_precision.c \
			flag_width.c \
			flags_minus_zero.c \
			ft_printf_percent.c \
			ft_printf_c.c \
			ft_printf_d_i_flags.c \
			ft_printf_d_i_flags2.c \
			ft_printf_d_i_flags3.c \
			ft_printf_d_i.c \
			ft_printf_h_flags.c \
			ft_printf_h_flags2.c \
			ft_printf_h_flags3.c \
			ft_printf_h_upper.c \
			ft_printf_h.c \
			ft_printf_p_flags.c \
			ft_printf_p.c \
			ft_printf_s.c \
			ft_printf_s_flags.c \
			ft_printf_s_flags2.c \
			ft_printf_u_flags.c \
			ft_printf_u_flags2.c \
			ft_printf_u.c \
			ft_printf.c 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
				make -sC ./libft/
				cp libft/libft.a .
				mv libft.a $(NAME)
				ar rc  $(NAME) $(OBJS)
				ranlib $(NAME)

all:	$(NAME)

clean:
				$(RM) $(OBJS)
				make -sC ./libft/ clean

fclean: clean
				$(RM) $(NAME)
				make -sC ./libft/ clean

re:				fclean all

.PHONY: all fclean re
