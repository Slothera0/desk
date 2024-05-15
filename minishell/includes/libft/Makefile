# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaron-t <mbaron-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 09:58:08 by mbaron-t          #+#    #+#              #
#    Updated: 2023/11/13 16:36:30 by mbaron-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS_PATH = ./

CFLAGS = -Wall -Wextra -Werror

F_OBJS = .objs/

SRCS =	./ft_isalpha.c \
./ft_isdigit.c \
./ft_isalnum.c \
./ft_isascii.c \
./ft_isprint.c \
./ft_strlen.c \
./ft_memset.c \
./ft_bzero.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_toupper.c \
./ft_tolower.c \
./ft_strchr.c \
./ft_strrchr.c \
./ft_strncmp.c \
./ft_strnstr.c \
./ft_atoi.c \
./ft_strlcpy.c \
./ft_strlcat.c \
./ft_memchr.c \
./ft_memcmp.c \
./ft_strdup.c \
./ft_calloc.c \
./ft_substr.c \
./ft_strjoin.c \
./ft_strtrim.c \
./ft_split.c \
./ft_itoa.c \
./ft_strmapi.c \
./ft_striteri.c \
./ft_putchar_fd.c \
./ft_putstr_fd.c \
./ft_putendl_fd.c \
./ft_putnbr_fd.c \
./ft_lstnew_bonus.c \
./ft_lstadd_front_bonus.c \
./ft_lstsize_bonus.c \
./ft_lstlast_bonus.c \
./ft_lstadd_back_bonus.c \
./ft_lstdelone_bonus.c \
./ft_lstclear_bonus.c \
./ft_lstiter_bonus.c \
./ft_lstmap_bonus.c \
./ft_arraylen.c \
./ft_atoll.c \
./ft_free_array.c \
./ft_strlen_c.c \
./ft_strdup_stop.c

OBJS = $(SRCS:%.c=$(F_OBJS)%.o)
OBJS_D = $(OBJS:$(F_OBJS)%.o=$(F_OBJS)%.d)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(F_OBJS)%.o : %.c
	mkdir -p $(F_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(F_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re