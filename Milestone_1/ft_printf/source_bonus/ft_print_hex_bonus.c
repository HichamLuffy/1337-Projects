/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:41 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/25 10:53:33 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	absolute(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	count_puthex(unsigned int args)
{
	int		i;
	int		digits[32];
	int		count;

	count = 0;
	i = 0;
	while (args >= 16)
	{
		digits[i++] = absolute(args % 16);
		args /= 16;
	}
	digits[i] = absolute(args);
	while (i >= 0 && count != -1)
	{
		count++;
		i--;
	}
	return (count);
}

int	handle_padding_and_prefix(unsigned int args, t_format *format, \
								int is_upper, int *padding)
{
	int	count;

	count = 0;
	if (!format->is_minus && (!format->is_zero || format->has_precision))
		count += ft_putpad(' ', *padding);
	if (format->is_hash && args != 0)
	{
		if (is_upper)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	if (!format->is_minus && format->is_zero && !format->has_precision)
		count += ft_putpad('0', *padding);
	return (count);
}

int	ft_puthex(unsigned int args, char *base, int is_upper, t_format *format)
{
	int	count;
	int	len;
	int	padding;
	int	zero_padding;

	count = 0;
	zero_padding = clc_pad_len(args, format, &len, &padding);
	count += handle_padding_and_prefix(args, format, is_upper, &padding);
	count += ft_putpad('0', zero_padding);
	if (len > 0)
		count += write_hex_number(args, base);
	if (format->is_minus)
		count += ft_putpad(' ', padding);
	return (count);
}
