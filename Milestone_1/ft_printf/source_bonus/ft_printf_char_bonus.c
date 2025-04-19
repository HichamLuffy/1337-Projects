/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:51 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 18:34:37 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c, t_format *format)
{
	int	padding;
	int	count;

	count = 0;
	padding = format->width - 1;
	if (padding < 0)
		padding = 0;
	if (!format->is_minus)
	{
		if (format->is_zero)
			count += ft_putpad('0', padding);
		else
			count += ft_putpad(' ', padding);
	}
	count += write(1, &c, 1);
	if (format->is_minus)
		count += ft_putpad(' ', padding);
	return (count);
}
