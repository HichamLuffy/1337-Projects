/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:48:46 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/05 15:41:00 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dis_error(t_stack **stack)
{
	ft_lstclear(stack);
	write(2, "Error\n", 6);
	exit(1);
}

int	stacksorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	fill_a(&a, av);
	dub_check(a);
	assign_indices(a, ft_lstsize(a));
	if (!stacksorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_3(&a);
		else
			sort_large_stack(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (1);
}
