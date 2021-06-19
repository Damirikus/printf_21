NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc 

INC		= ./includes/libftprintf.h

SRCS	= ft_printf.c ./includes/auxiliary.c ./includes/ft_char.c \
		  ./includes/ft_integers_part.c ./includes/ft_integers.c ./includes/ft_percent.c	\
		  ./includes/ft_string.c ./includes/ft_unsigned.c ./includes/ft_utils_second.c \
		  ./includes/ft_utils.c ./includes/ft_xp_second.c \
		  ./includes/ft_xp_th.c ./includes/ft_xp.c \
		  ./includes/parcer.c 

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib ${NAME}
	
all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
	
	
clean:
	-rm -rf $(OBJS) 

fclean: clean	
	-rm -rf $(NAME)
	
re:		fclean all

.PHONY: all clean fclean re
