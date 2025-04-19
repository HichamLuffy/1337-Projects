CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = src/ft_putstr.c src/ft_printf.c src/ft_print_hex.c src/ft_print_int.c \
		src/ft_print_ptr.c src/ft_print_unsigned.c src/ft_printf_char.c \
		src/ft_printf_str.c

SRC_BONUS = source_bonus/ft_putstr_bonus.c source_bonus/ft_printf_bonus.c source_bonus/ft_print_hex_bonus.c source_bonus/ft_print_int_bonus.c \
		source_bonus/ft_print_ptr_bonus.c source_bonus/ft_print_unsigned_bonus.c source_bonus/ft_printf_char_bonus.c \
		source_bonus/ft_printf_str_bonus.c source_bonus/format.c source_bonus/helpers.c \
		source_bonus/padding.c source_bonus/writers.c

BHEADER = source_bonus/ft_printf_bonus.h

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

src/%.o: src/%.c src/ft_printf.h
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(OBJ_BONUS)
	@rm -f $(OBJ) $(NAME)
	ar rcs $(NAME) $(OBJ_BONUS)

source_bonus/%.o: source_bonus/%.c $(BHEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean