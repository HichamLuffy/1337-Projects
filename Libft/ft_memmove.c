/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:59:07 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/06 19:56:18 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			j;

	if (dst == src || len == 0)
		return (dst);
	ptr1 = (unsigned char *) dst;
	ptr2 = (unsigned char *) src;
	if (ptr1 > ptr2)
	{
		while (len > 0)
		{
			len--;
			ptr1[len] = ptr2[len];
		}
	}
	else
	{
		i = 0;
		j = 0;
		while (i < len)
			ptr1[i++] = ptr2[j++];
	}
	return (ptr1);
}
