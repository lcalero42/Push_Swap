CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = operations.c operations_2.c operations_3.c parse_input.c print_error.c ../libft/ft_isdigit.c \
		../libft/ft_atoi.c ../libft/ft_putstr_fd.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
		checker_functions.c main.c
HEADERS = push_swap.h libft/libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all = $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c ${HEADERS}
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re