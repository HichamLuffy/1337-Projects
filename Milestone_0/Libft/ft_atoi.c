/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:54:12 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/06 18:19:03 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	var_init(int *i, int *is_neg, long long *num)
{
	*i = 0;
	*num = 0;
	*is_neg = 1;
}

static int	check_overflow(long long num, char digit, int is_neg)
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
