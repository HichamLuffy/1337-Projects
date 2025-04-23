NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = mandatory/ft_split.c mandatory/main.c mandatory/utils.c mandatory/ft_putstr_fd.c \
		mandatory/parsing.c mandatory/ft_strchr.c

SRC_BONUS = bonus/ft_split_bonus.c bonus/main_bonus.c bonus/utils_bonus.c bonus/parsing_bonus.c \
		bonus/process_utils_bonus.c bonus/filename_bonus.c bonus/pipex_utils_bonus.c \
		bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c bonus/pipex_helpers_bonus.c bonus/ft_strchr_bonus.c

SRC_OBJS = ${SRC:.c=.o}
SRCB_OBJS = ${SRC_BONUS:.c=.o}

mandatory/%.o: mandatory/%.c mandatory/header.h
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/header_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(SRC_OBJS)
	$(CC) $(FLAGS) $^ -o $@

bonus: $(SRCB_OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	rm -f $(SRC_OBJS) $(SRCB_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean