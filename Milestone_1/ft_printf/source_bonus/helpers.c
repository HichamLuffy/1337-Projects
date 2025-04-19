/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:12:58 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/26 09:36:59 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	var_init(int *i, int *is_neg, long long *num)
{
	*i = 0;
	*num = 0;
	*is_neg = 1;
}

int	check_overflow(long long num, char digit, int is_neg)
{
	if (num > LLONG_MAX / 10 || \
	(num == LLONG_MAX / 10 && (digit - '0') > LLONG_MAX % 10))
	{
		if (is_neg == -1)
			return (0);
		else if (is_neg == 1)
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			is_neg;
	long long	num;

	var_init(&i, &is_neg, &num);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(num, str[i], is_neg) != 1)
			return (check_overflow(num, str[i], is_neg));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_neg);
}

void	handle_spaces_and_width(const char **str, t_format *format)
{
	if (format->is_space)
		skip_spaces(str);
	if (ft_isdigit(**str))
		format->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
}

void	handle_precision(const char **str, t_format *format)
{
	if (**str == '.')
	{
		format->has_precision = 1;
		(*str)++;
		if (ft_isdigit(**str))
			format->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
}
