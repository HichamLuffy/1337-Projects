/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:56:04 by hfhad             #+#    #+#             */
/*   Updated: 2024/10/30 18:45:13 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;
	int	is_here;

	is_here = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			j = i;
			is_here = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	if (is_here == 0)
		return (NULL);
	return ((char *)(s + j));
}
