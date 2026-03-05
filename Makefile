NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/error.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/parse_flags.c \
       $(SRC_DIR)/parse_args.c \
       $(SRC_DIR)/stack_init.c \
       $(SRC_DIR)/stack_ops_swap.c \
       $(SRC_DIR)/stack_ops_push.c \
       $(SRC_DIR)/stack_ops_rotate.c \
       $(SRC_DIR)/stack_ops_revrotate.c \
       $(SRC_DIR)/disorder.c \
       $(SRC_DIR)/sort_utils.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_simple.c \
       $(SRC_DIR)/sort_medium.c \
       $(SRC_DIR)/sort_complex.c \
       $(SRC_DIR)/sort_turkish.c \
       $(SRC_DIR)/sort_adaptive.c \
       $(SRC_DIR)/bench.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
