/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:46 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:26:51 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
		digits[i++] = absolute(args % base_len);
		args /= base_len;
	}
	digits[i] = absolute(args);
	while (i >= 0 && count != -1)
	{
		count += write(1, &base[digits[i]], 1);
		i--;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (count != -1)
		count += ft_puthex_ptr(address, "0123456789abcdef");
	return (count);
}
