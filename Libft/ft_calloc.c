/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:54:14 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/08 11:56:20 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*r;
	size_t			i;

	if ((long long)count < 0 || (long long)size < 0)
		return (NULL);
	r = (unsigned char *)malloc(count * size);
	if (!r)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		r[i] = 0;
		i++;
	}
	return ((void *)r);
}
