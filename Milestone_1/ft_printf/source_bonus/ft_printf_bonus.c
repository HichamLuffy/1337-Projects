/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:41:33 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/24 18:41:12 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	isformat(char c)
{
	char	*format;

	format = "cspdiuxX%0123456789-0.# +";
	while (*format)
	{
		if (c == *format)
			return (1);
		format++;
	}
	return (0);
}

int	ft_putcharb(char c)
{
	return (write(1, &c, 1));
}

static int	process_format(const char **str, va_list args, int *count)
{
	t_format	format;
	int			result;

	result = 0;
	if (isformat(*(*str + 1)))
	{
		(*str)++;
		parse_format(str, &format);
		result = ft_print_value(**str, args, &format);
	}
	else
		result = 0;
	*count += result;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		result;

	count = 0;
	result = 0;
	va_start(args, str);
	if (write(1, 0, 0) < 0)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%')
			result = process_format(&str, args, &count);
		else
			result = ft_putcharb(*str);
		if (result == -1)
			return (va_end(args), -1);
		count += result;
		str++;
	}
	va_end(args);
	return (count);
}
