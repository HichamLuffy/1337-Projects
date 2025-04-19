/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:00:01 by hfhad             #+#    #+#             */
/*   Updated: 2024/10/30 15:59:34 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pk;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	pk = (char *) malloc(i + 1);
	if (!pk)
		return (NULL);
	while (s1[j] != '\0')
	{
		pk[j] = s1[j];
		j++;
	}
	pk[j] = '\0';
	return (pk);
}
