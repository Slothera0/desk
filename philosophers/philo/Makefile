CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include

IFLAGS = \
         -I $(INCLUDE_DIR) \

DFLAGS = -MD -MP

SRC = main.c \
create_thread.c \
end_thread.c \
init_philo.c \
init_mutex.c \
destroy_mutex.c \
monitoring.c \
routine.c \
routine_utils.c \
time_utils.c \
utils.c \
clear_data.c

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

NAME = philo

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

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all