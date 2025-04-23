NAME = push_swap

BONUS_NAME = checker

FLAGS = -Wall -Werror -Wextra

SRC = mandatory/ft_split.c mandatory/main.c mandatory/rotate_ops.c mandatory/stack_ops.c mandatory/main_utils.c \
		mandatory/push_swap_ops.c mandatory/sort_arr.c mandatory/stack_sort.c mandatory/ft_atoi.c mandatory/helper_functions.c \
		mandatory/merge_utils.c mandatory/rev_rotate_ops.c mandatory/sort_helpers.c mandatory/stack_utils.c mandatory/parsing.c

OBJ = ${SRC:.c=.o}

SRC_BONUS = bonus/ft_split.c bonus/main.c bonus/rotate_ops.c bonus/stack_ops.c bonus/main_utils.c \
		bonus/push_swap_ops.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/ft_atoi.c \
		bonus/rev_rotate_ops.c bonus/stack_utils.c bonus/parsing.c bonus/instr_utils.c bonus/check_lines.c

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

mandatory/%.o: mandatory/%.c mandatory/header.h
	cc $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/header.h
	cc $(FLAGS) -c $< -o $@


$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@echo "🧹 Object files removed."

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@echo "🗑️ Executables removed."

re: fclean all

.PHONY: clean
