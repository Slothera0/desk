CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include

IFLAGS = \
         -I $(INCLUDE_DIR) 

DFLAGS = -MD -MP

SRC = push_swap.c \
      create_chunck.c \
	  instruction.c \
	  math.c \
	  one_arg.c \
	  sort_tab.c \
	  utils.c \
	  free.c

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

NAME = push_swap

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p .build
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean
	$(MAKE) all
