NAME = libftprintf.a

SOURCES = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	cc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re