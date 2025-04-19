/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:44 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:26:48 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int args)
{
	long	num;
	int		div;
	char	c;
	int		count;

	num = args;
	count = 0;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	div = 1;
	while ((num / div) >= 10)
		div *= 10;
	while (div >= 1 && count != -1)
	{
		c = (num / div) % 10 + '0';
		count += write(1, &c, 1);
		div /= 10;
	}
	return (count);
}
