/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:48:49 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/06 15:41:24 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	dis_error(t_stack **stack)
{
	ft_lstclear(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	stop_error(t_stack **a, t_stack **b)
{
	if (*a)
		ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	cleanup(t_list **instructions, t_stack **a, t_stack **b)
{
	ft_instclear(instructions, free);
	ft_lstclear(a);
	ft_lstclear(b);
}
