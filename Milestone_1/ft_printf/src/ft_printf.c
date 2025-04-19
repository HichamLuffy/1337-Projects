/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:33 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:36:31 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isformat(char c)
{
	char	*format;

	format = "cspdiuxX%";
	while (*format)
	{
		if (c == *format)
			return (1);
		format++;
	}
	return (0);
}

void	vars(int *count, int *result, int *i)
{
	*count = 0;
	*result = 0;
	*i = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		result;
	int		i;

	vars(&count, &result, &i);
	va_start(args, str);
	if (write(1, 0, 0) < 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (isformat(str[i + 1]))
				result = ft_print_value(str[++i], args);
			else
				result = 0;
		}
		else
			result = ft_putchar(str[i]);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
