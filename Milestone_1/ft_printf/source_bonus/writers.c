/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:03:42 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 15:37:29 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_hex_number(unsigned int args, char *base)
{
	int	digits[32];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args >= 16)
	{
		digits[i++] = args % 16;
		args /= 16;
	}
	digits[i] = args;
	while (i >= 0)
		count += write(1, &base[digits[i--]], 1);
	return (count);
}

int	write_int_number(int args, long num)
{
	int		count;
	int		div;
	char	c;

	count = 0;
	if (args == INT_MIN)
	{
		count += write(1, "2147483648", 10);
	}
	else
	{
		div = 1;
		while ((num / div) >= 10)
			div *= 10;
		while (div >= 1)
		{
			c = (num / div) % 10 + '0';
			count += write(1, &c, 1);
			div /= 10;
		}
	}
	return (count);
}
