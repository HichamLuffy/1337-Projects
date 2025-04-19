/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:39:48 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 22:31:11 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putpad(char c, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
	return (count);
}

int	clc_pad_len(unsigned int args, t_format *format, int *len, int *padding)
{
	int	zero_padding;

	*len = count_puthex(args);
	if (args == 0 && format->has_precision && format->precision == 0)
		*len = 0;
	if (format->has_precision && format->precision > *len)
		zero_padding = format->precision - *len;
	else
		zero_padding = 0;
	*padding = format->width - (*len + zero_padding);
	if (format->is_hash && args != 0)
		*padding -= 2;
	if (*padding < 0)
		*padding = 0;
	return (zero_padding);
}

int	handle_pre_padding(int is_negative, int *padding, \
						t_format *format, int args)
{
	int	count;

	count = 0;
	if (!format->is_minus)
	{
		if (format->is_zero && !format->has_precision)
		{
			count += handle_pad_signs(is_negative, padding, format, args);
			if (is_negative && args == INT_MIN && \
				format->width > 11 && !format->is_zero)
				count += write(1, " ", 1);
		}
		else
		{
			if (is_negative && args == INT_MIN && format->width > 11 && \
				format->has_precision && format->precision <= 11)
				count += write(1, " ", 1);
			else if (is_negative && args == INT_MIN && format->width > 11 && \
					!format->has_precision)
				count += write(1, " ", 1);
			count += ft_putpad(' ', *padding);
		}
	}
	return (count);
}

int	handle_post_padding(int is_negative, t_format *format)
{
	int	count ;

	count = 0;
	if (!format->is_zero || format->has_precision)
	{
		if (is_negative)
			count += write(1, "-", 1);
		else if (format->is_plus)
			count += write(1, "+", 1);
		else if (format->is_space)
			count += write(1, " ", 1);
	}
	return (count);
}
