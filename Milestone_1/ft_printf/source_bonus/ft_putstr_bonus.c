/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:04:45 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 18:16:42 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_value(char c, va_list args, t_format *format)
{
	if (c == '%')
		return (ft_putchar(c, format));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int), format));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), format));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *), format));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int), format));
	else if (c == 'u')
		return (ft_putunsd(va_arg(args, unsigned int), format));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), \
							"0123456789abcdef", 0, format));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), \
							"0123456789ABCDEF", 1, format));
	else
		return (0);
}
