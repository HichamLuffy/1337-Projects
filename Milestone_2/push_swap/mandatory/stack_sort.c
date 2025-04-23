/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:14:30 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/06 15:38:57 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && first < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

t_cost	calculate_cost(t_stack *a, t_stack *b, int b_pos)
{
	t_cost	cost;
	t_stack	*tmp;
	int		size_a;
	int		size_b;
	int		target_pos;

	ft_memset(&cost, 0, sizeof(t_cost));
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	tmp = get_node_at_position(b, b_pos);
	target_pos = find_target_position(a, tmp->index);
	if (b_pos <= size_b / 2)
		cost.rb_count = b_pos;
	else
		cost.rrb_count = size_b - b_pos;
	if (target_pos <= size_a / 2)
		cost.ra_count = target_pos;
	else
		cost.rra_count = size_a - target_pos;
	cost.total = cost.ra_count + cost.rb_count + \
					cost.rra_count + cost.rrb_count;
	return (cost);
}

void	process_best_move(t_stack **a, t_stack **b)
{
	t_cost	best_cost;
	t_cost	current_cost;
	int		best_pos;
	int		i;

	ft_memset(&best_cost, 0, sizeof(t_cost));
	best_cost.total = INT_MAX;
	best_pos = 0;
	i = 0;
	while (i < ft_lstsize(*b))
	{
		current_cost = calculate_cost(*a, *b, i);
		if (current_cost.total < best_cost.total)
		{
			best_cost = current_cost;
			best_pos = i;
		}
		i++;
	}
	execute_moves(a, b, best_cost);
}

void	sort_large_stack(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_lstsize(*a);
	move_to_b(a, b, size);
	sort_3(a);
	while (*b)
		process_best_move(a, b);
	final_rotation(a);
}

void	final_rotation(t_stack **a)
{
	int	min_pos;
	int	size_a;

	min_pos = find_position(*a, 0);
	size_a = ft_lstsize(*a);
	if (min_pos <= size_a / 2)
		while (min_pos--)
			ra(a);
	else
		while (min_pos++ < size_a)
			rra(a);
}
