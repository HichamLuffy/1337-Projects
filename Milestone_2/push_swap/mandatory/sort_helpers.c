/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:36:46 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/06 15:38:59 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_position(t_stack *stack, int index)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_target_position(t_stack *a, int b_index)
{
	t_stack	*tmp;
	int		target_pos;
	int		closest_bigger;
	int		found;

	tmp = a;
	target_pos = 0;
	closest_bigger = INT_MAX;
	found = 0;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < closest_bigger)
		{
			closest_bigger = tmp->index;
			found = 1;
		}
		tmp = tmp->next;
	}
	if (!found)
		return (0);
	return (find_position(a, closest_bigger));
}

t_stack	*get_node_at_position(t_stack *stack, int position)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (i < position && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	execute_moves(t_stack **a, t_stack **b, t_cost cost)
{
	while (cost.ra_count > 0 && cost.rb_count > 0)
	{
		rr(a, b);
		cost.ra_count--;
		cost.rb_count--;
	}
	while (cost.rra_count > 0 && cost.rrb_count > 0)
	{
		rrr(a, b);
		cost.rra_count--;
		cost.rrb_count--;
	}
	while (cost.ra_count--)
		ra(a);
	while (cost.rb_count--)
		rb(b);
	while (cost.rra_count--)
		rra(a);
	while (cost.rrb_count--)
		rrb(b);
	pa(b, a);
}

void	move_to_b(t_stack **a, t_stack **b, int a_len)
{
	while (ft_lstsize(*a) > (a_len / 2) + 1)
	{
		if (stacksorted(*a) && *b == NULL)
			return ;
		if ((*a)->index >= a_len / 2 && (*a)->index != 0)
			ra(a);
		else
			pb(a, b);
	}
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index != 0 && (*a)->index != a_len - 1 \
			&& (*a)->index != a_len - 2)
			pb(a, b);
		else
			ra(a);
	}
}
