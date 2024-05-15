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

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g

F_OBJS = .objs/
F_PARSE = src/parse/
F_TOKENS = tokens/
F_EXPANDER = expander/
F_PIPES = pipes/
F_CMDS = cmds/
F_HEREDOC = heredoc/
F_EXEC = src/exec/
F_BUILTINS = builtins/

SRCS =	./src/minishell.c ./src/signals.c ./src/free.c ./src/init.c \
		./$(F_PARSE)parse.c ./$(F_PARSE)utils.c ./$(F_PARSE)error.c\
		./$(F_PARSE)$(F_HEREDOC)heredoc.c ./$(F_PARSE)$(F_HEREDOC)heredoc_utils.c \
		./$(F_PARSE)$(F_TOKENS)tokens.c ./$(F_PARSE)$(F_TOKENS)tokens_utils.c ./$(F_PARSE)$(F_TOKENS)tokens_utils2.c ./$(F_PARSE)$(F_TOKENS)token_getter.c ./$(F_PARSE)$(F_TOKENS)ambiguous_redir.c \
		./$(F_PARSE)$(F_EXPANDER)expander.c ./$(F_PARSE)$(F_EXPANDER)expander_utils.c ./$(F_PARSE)$(F_EXPANDER)replace_var.c ./$(F_PARSE)$(F_EXPANDER)removers.c ./$(F_PARSE)$(F_EXPANDER)pro_expand.c \
		./$(F_PARSE)$(F_EXPANDER)find_var.c ./$(F_PARSE)$(F_EXPANDER)find_var_utils.c ./$(F_PARSE)$(F_EXPANDER)pre_expand.c ./$(F_PARSE)$(F_EXPANDER)exit_var.c\
		./$(F_PARSE)$(F_PIPES)pipes.c ./$(F_PARSE)$(F_PIPES)pipes_utils.c ./$(F_PARSE)$(F_PIPES)pipes_utils2.c \
		./$(F_PARSE)$(F_CMDS)cmds.c ./$(F_PARSE)$(F_CMDS)cmds_utils.c ././$(F_PARSE)$(F_CMDS)open_error.c ./$(F_PARSE)$(F_CMDS)redirs.c ./$(F_PARSE)$(F_CMDS)redirs_utils.c \
        ./$(F_EXEC)$(F_BUILTINS)cd.c \
        ./$(F_EXEC)$(F_BUILTINS)echo.c\
        ./$(F_EXEC)$(F_BUILTINS)env.c \
        ./$(F_EXEC)$(F_BUILTINS)exit.c \
        ./$(F_EXEC)$(F_BUILTINS)export.c \
        ./$(F_EXEC)$(F_BUILTINS)pwd.c \
        ./$(F_EXEC)$(F_BUILTINS)unset.c \
        ./$(F_EXEC)free_data.c \
        ./$(F_EXEC)exec.c \
        ./$(F_EXEC)error.c \
        ./$(F_EXEC)find_path.c \
        ./$(F_EXEC)exec_builtins.c

OBJS = $(SRCS:%.c=$(F_OBJS)%.o)
OBJS_D = $(OBJS:$(F_OBJS)%.o=$(F_OBJS)%.d)

NAME = minishell

INCLUDES = ./includes
LIBFT_PATH = $(INCLUDES)/libft/
LIBFT = $(LIBFT_PATH)libft.a
HEADER = $(INCLUDES)/minishell.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

$(F_OBJS)%.o : %.c $(HEADER)
	mkdir -p $(F_OBJS) $(F_OBJS)$(F_PARSE) $(F_OBJS)$(F_PARSE)$(F_TOKENS) $(F_OBJS)$(F_PARSE)$(F_EXPANDER) $(F_OBJS)$(F_PARSE)$(F_HEREDOC) $(F_OBJS)$(F_PARSE)$(F_PIPES) $(F_OBJS)$(F_PARSE)$(F_CMDS) $(F_OBJS)$(F_EXEC) $(F_OBJS)$(F_EXEC)$(F_BUILTINS)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_PATH)

valgrind: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --suppressions=./mask_readline_leaks.supp --read-var-info=yes --show-mismatched-frees=yes --track-fds=all --trace-children=yes ./minishell

clean:
	rm -rf $(F_OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE valgrind
