/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:38 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:36:20 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_print_value(char c, va_list args);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putptr(void *ptr);
int	ft_puthex(unsigned int args, char *base);
int	ft_putnbr(int args);
int	ft_putunsd(unsigned int args);
int	absolute(int i);
int	ft_strlen(char *str);

#endif