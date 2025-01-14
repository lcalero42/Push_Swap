CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = operations.c operations_2.c operations_3.c parse_input.c print_error.c ../libft/ft_isdigit.c \
		../libft/ft_atoi.c ../libft/ft_putstr_fd.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
		checker_functions.c main.c is_sorted.c ../libft/ft_split.c turkish_algorithm.c \
		algorithm_utils.c solver_utils.c sort_three.c apply_moves_b.c apply_moves_a.c \
		solver_utils_a.c sort.c
BONUS_SRCS = operations.c operations_2.c operations_3.c parse_input.c print_error.c ../libft/ft_isdigit.c \
		../libft/ft_atoi.c ../libft/ft_putstr_fd.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
		checker_functions.c is_sorted.c ../libft/ft_split.c turkish_algorithm.c \
		algorithm_utils.c solver_utils.c sort_three.c apply_moves_b.c apply_moves_a.c \
		solver_utils_a.c sort.c
HEADERS = push_swap.h libft/libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

BONUS = checker
BONUS_OBJ = $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))

all = $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo building push_swap...

$(BONUS): $(BONUS_OBJ)
	@$(CC) $(FLAGS) -o $(BONUS) $(OBJS)
	@echo building bonus...

$(OBJS_DIR)/%.o: %.c ${HEADERS}
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

bonus: $(BONUS)

clean:
	@rm -rf $(OBJS_DIR) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo removing objects files...

fclean: clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re