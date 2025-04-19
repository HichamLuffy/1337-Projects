/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:49 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 15:42:23 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_countunsd(unsigned int args)
{
	unsigned int	num;
	int				div;
	int				count;

	num = args;
	count = 0;
	div = 1;
	while ((num / div) >= 10)
		div *= 10;
	while (div >= 1 && count != -1)
	{
		count ++;
		div /= 10;
	}
	return (count);
}

int	ft_put_number_unsigned(unsigned int num)
{
	char	c;
	int		count;
	int		div;

	count = 0;
	div = 1;
	while ((num / div) >= 10)
		div *= 10;
	while (div >= 1)
	{
		c = (num / div) % 10 + '0';
		count += write(1, &c, 1);
		div /= 10;
	}
	return (count);
}

int	put_padding(t_format *format, int num_len, int zero_pad, int *space_pad)
{
	int	count;

	count = 0;
	if (format->width > (num_len + zero_pad))
		*space_pad = format->width - (num_len + zero_pad);
	if (!format->is_minus)
	{
		while ((*space_pad)-- > 0)
		{
			if (format->is_zero && !format->has_precision)
				count += write(1, "0", 1);
			else
				count += write(1, " ", 1);
		}
	}
	while (zero_pad-- > 0)
		count += write(1, "0", 1);
	return (count);
}

int	ft_putunsd(unsigned int args, t_format *format)
{
	unsigned int	num;
	int				num_len;
	int				count;
	int				zero_pad;
	int				space_pad;

	num = args;
	count = 0;
	if (num == 0 && format->has_precision && format->precision == 0)
		num_len = 0;
	else
		num_len = ft_countunsd(num);
	zero_pad = 0;
	if (format->has_precision && format->precision > num_len)
		zero_pad = format->precision - num_len;
	space_pad = 0;
	count += put_padding(format, num_len, zero_pad, &space_pad);
	if (num_len > 0)
		count += ft_put_number_unsigned(num);
	while (space_pad-- > 0)
		count += write(1, " ", 1);
	return (count);
}
