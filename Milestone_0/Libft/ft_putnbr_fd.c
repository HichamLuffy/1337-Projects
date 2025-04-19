/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:25:00 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/06 19:56:55 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		div;
	char	c;

	num = n;
	if (fd < 0)
		return ;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	div = 1;
	while ((num / div) >= 10)
		div *= 10;
	while (div >= 1)
	{
		c = (num / div) % 10 + '0';
		write(fd, &c, 1);
		div /= 10;
	}
}
