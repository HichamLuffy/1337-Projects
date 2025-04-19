/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:41 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:26:45 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_puthex(unsigned int args, char *base)
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
		count += write(1, &base[digits[i--]], 1);
	return (count);
}
