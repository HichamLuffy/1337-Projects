/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:59 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 17:59:43 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	padding_handler(t_format *format, int padding)
{
	int	count;

	count = 0;
	if (format->is_zero)
		count += ft_putpad('0', padding);
	else
		count += ft_putpad(' ', padding);
	return (count);
}

int	ft_putstr(char *str, t_format *format)
{
	int	len;
	int	padding;
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (format->has_precision && format->precision == 0)
		len = 0;
	if (format->has_precision && format->precision < len)
		len = format->precision;
	padding = format->width - len;
	if (padding < 0)
		padding = 0;
	if (!format->is_minus)
		count += padding_handler(format, padding);
	count += write(1, str, len);
	if (format->is_minus)
		count += ft_putpad(' ', padding);
	return (count);
}
