/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:38 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:36:01 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_format
{
	int	is_minus;
	int	is_zero;
	int	is_hash;
	int	is_space;
	int	is_plus;
	int	width;
	int	precision;
	int	has_precision;
}	t_format;

int		ft_printf(const char *str, ...);
int		ft_print_value(char c, va_list args, t_format *format);
int		ft_putstr(char *str, t_format *format);
int		ft_putchar(char c, t_format *format);
int		ft_putptr(void *ptr, t_format *format);
int		ft_puthex(unsigned int args, char *base, int is_upper, \
					t_format *format);
int		ft_putnbr(int args, t_format *format);
int		ft_putunsd(unsigned int args, t_format *format);
int		absolute(int i);
int		ft_strlen(char *str);
void	parse_format(const char **str, t_format *format);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_putpad(char c, int count);
void	handle_precision(const char **str, t_format *format);
void	handle_spaces_and_width(const char **str, t_format *format);
int		ft_isdigit(int c);
void	skip_spaces(const char **str);
int		write_hex_number(unsigned int args, char *base);
int		clc_pad_len(unsigned int args, t_format *format, \
					int *len, int *padding);
int		count_puthex(unsigned int args);
int		clc_pad_int(long *num, t_format *format, int *len, int *padding);
int		count_putnbr(int args);
int		write_int_number(int args, long num);
int		handle_post_padding(int is_negative, t_format *format);
int		handle_pre_padding(int is_negative, int *padding, \
						t_format *format, int args);
int		handle_pad_signs(int is_negative, int *padding, \
							t_format *format, int args);

#endif
