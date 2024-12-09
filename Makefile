NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_puthexa.c ft_putaddress.c ft_putchar.c \
			ft_putnbr.c ft_putstr.c ft_puthexau.c \
			ft_unsigned.c ft_printf.c

OBJS = $(SRC:.c=.o)


$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
