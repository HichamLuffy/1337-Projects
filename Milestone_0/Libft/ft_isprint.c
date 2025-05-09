/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:38:10 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/08 12:16:07 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	n;

	n = c;
	if (c < 0 || c > 255)
		return (0);
	if (n >= 32 && n <= 126)
		return (1);
	return (0);
}
