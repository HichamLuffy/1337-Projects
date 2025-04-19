/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:51:38 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/22 18:02:04 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

void	skip_spaces(const char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	parse_format(const char **str, t_format *format)
{
	ft_memset(format, 0, sizeof(*format));
	while (**str == '0' || **str == '-' || \
		**str == '#' || **str == ' ' || **str == '+')
	{
		if (**str == ' ')
			format->is_space = 1;
		if (**str == '0')
			format->is_zero = 1;
		if (**str == '-')
		{
			format->is_minus = 1;
			format->is_zero = 0;
		}
		if (**str == '#')
			format->is_hash = 1;
		if (**str == '+')
		{
			format->is_plus = 1;
			format->is_space = 0;
		}
		(*str)++;
	}
	handle_spaces_and_width(str, format);
	handle_precision(str, format);
}
