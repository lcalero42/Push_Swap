CC = cc
FLAGS = -Wall -Wextra -Werror

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
BOLD = \033[1m

NAME = push_swap

SRCS = operations.c operations_2.c operations_3.c parse_input.c print_error.c ../libft/ft_isdigit.c \
		../libft/ft_atoi.c ../libft/ft_putstr_fd.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
		parsing_checkers.c main.c is_sorted.c ../libft/ft_split.c turkish_algorithm.c \
		algorithm_utils.c solver_utils.c sort_three.c apply_moves_b.c apply_moves_a.c \
		solver_utils_a.c sort.c
BONUS_SRCS = operations.c operations_2.c operations_3.c parse_input.c print_error.c ../libft/ft_isdigit.c \
		../libft/ft_atoi.c ../libft/ft_putstr_fd.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
		parsing_checkers.c is_sorted.c ../libft/ft_split.c algorithm_utils.c solver_utils.c sort_three.c \
		solver_utils_a.c checker_bonus.c ../libft/get_next_line.c ../libft/ft_memcpy.c \
		../libft/ft_strchr.c ../libft/ft_bzero.c checker_operations_bonus.c checker_operations_bonus_2.c \
		checker_operations_bonus_3.c
HEADERS = push_swap.h libft/libft.h

OBJS_DIR = objects
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

BONUS = checker
BONUS_OBJ = $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(BONUS): $(BONUS_OBJ)
	@echo "$(BOLD)$(BLUE)Linking $(BONUS)...$(RESET)"
	@$(CC) $(FLAGS) -o $(BONUS) $(BONUS_OBJ)

$(OBJS_DIR)/%.o: %.c ${HEADERS}
	@mkdir -p $(OBJS_DIR)
	@echo "$(BOLD)$(GREEN)Compiling$(RESET) $<..."
	@$(CC) $(FLAGS) -c $< -o $@ >/dev/null 2>&1

$(LIBFT): ${HEADERS}
	@echo "$(BOLD)$(CYAN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) all >/dev/null 2>&1

bonus: $(LIBFT) $(BONUS)

clean:
	@echo "$(BOLD)$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean >/dev/null 2>&1

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re bonus