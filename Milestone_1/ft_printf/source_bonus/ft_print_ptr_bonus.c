/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:46 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 12:44:45 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hexlen(unsigned long args)
{
	int				i;
	int				digits[32];
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = 16;
	i = 0;
	while (args >= base_len)
	{
		digits[i++] = args % base_len;
		args /= base_len;
	}
	digits[i] = args;
	while (i >= 0 && count != -1)
	{
		count++;
		i--;
	}
	return (count);
}

int	ft_puthex_ptr(unsigned long args, char *base)
{
	int				i;
	int				digits[32];
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base);
	i = 0;
	while (args >= base_len)
	{
		digits[i++] = args % base_len;
		args /= base_len;
	}
	digits[i] = args;
	while (i >= 0 && count != -1)
	{
		count += write(1, &base[digits[i]], 1);
		i--;
	}
	return (count);
}

int	ft_putptr_address(unsigned long address)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (address == 0)
		count += write(1, "0", 1);
	else
		count += ft_puthex_ptr(address, "0123456789abcdef");
	return (count);
}

void	init_vars(int *count, int *len, char *padding)
{
	*count = 0;
	*len = 2;
	*padding = ' ';
}

int	ft_putptr(void *ptr, t_format *format)
{
	unsigned long	address;
	int				count;
	int				len;
	char			padding;

	address = (unsigned long)ptr;
	init_vars(&count, &len, &padding);
	if (format->is_zero && !format->is_minus)
		padding = '0';
	len += ft_hexlen(address);
	if (address == 0)
		len = 3;
	if (format->is_minus)
	{
		count += ft_putptr_address(address);
		while (count < format->width)
			count += write(1, " ", 1);
	}
	else
	{
		while (count + len < format->width)
			count += write(1, &padding, 1);
		count += ft_putptr_address(address);
	}
	return (count);
}
