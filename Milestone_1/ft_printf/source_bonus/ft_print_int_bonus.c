/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:44 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 22:27:29 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_pad_signs(int is_negative, int *padding, t_format *format, int args)
{
	int	count;

	count = 0;
	if (format->is_zero && !format->has_precision)
	{
		if (format->is_space && !is_negative && !format->is_plus)
			count += write(1, " ", 1);
		if (is_negative)
			count += write(1, "-", 1);
		else if (format->is_plus)
			count += write(1, "+", 1);
		if (is_negative && args == INT_MIN && format->width > 11)
			count += write(1, "0", 1);
		count += ft_putpad('0', *padding);
	}
	return (count);
}

int	handle_pad(int is_negative, int *padding, t_format *format, int args)
{
	int	count;

	count = 0;
	count += handle_pre_padding(is_negative, padding, format, args);
	count += handle_post_padding(is_negative, format);
	return (count);
}

int	clc_pad_int(long *num, t_format *format, int *len, int *padding)
{
	int	zero_padding;
	int	is_negative;

	is_negative = (*num < 0);
	if (*num == INT_MIN)
		*num = (long)INT_MAX + 1;
	else if (*num < 0)
		*num = -(long)*num;
	if (*num == 0 && format->has_precision && format->precision == 0)
		*len = 0;
	else
		*len = count_putnbr(*num);
	if (format->has_precision && format->precision > *len)
		zero_padding = format->precision - *len;
	else
		zero_padding = 0;
	*padding = format->width - (*len + zero_padding + is_negative);
	if (!is_negative && (format->is_plus || format->is_space))
		(*padding)--;
	if (*padding < 0)
		*padding = 0;
	return (zero_padding);
}

int	count_putnbr(int args)
{
	long	num;
	int		div;
	char	c;
	int		count;

	num = args;
	count = 0;
	if (args == INT_MIN)
		return (11);
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	div = 1;
	while ((num / div) >= 10)
		div *= 10;
	while (div >= 1 && count != -1)
	{
		c = (num / div) % 10 + '0';
		count++;
		div /= 10;
	}
	return (count);
}

int	ft_putnbr(int args, t_format *format)
{
	long	num;
	int		count;
	int		padding;
	int		len;
	int		zero_padding;

	num = args;
	zero_padding = clc_pad_int(&num, format, &len, &padding);
	count = handle_pad((args < 0), &padding, format, args);
	if ((args < 0) && args == INT_MIN && format->precision > 11)
		zero_padding++;
	count += ft_putpad('0', zero_padding);
	if (len > 0)
		count += write_int_number(args, num);
	if (format->is_minus)
	{
		if ((args < 0) && args == INT_MIN && format->width > 11 && \
				format->has_precision && format->precision <= 11)
			count += write(1, " ", 1);
		else if ((args < 0) && args == INT_MIN && \
				format->width > 11 && !format->has_precision)
			count += write(1, " ", 1);
		count += ft_putpad(' ', padding);
	}
	return (count);
}
