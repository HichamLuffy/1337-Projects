/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:04:24 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/04 16:33:00 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*first;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = (*stack);
	last_node = ft_lstlast(*stack);
	(*stack) = first->next;
	(*stack)->prev = NULL;
	last_node->next = first;
	first->prev = last_node;
	first->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last_node;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last_node = ft_lstlast(*stack);
	second_last = last_node->prev;
	second_last->next = NULL;
	last_node->prev = NULL;
	last_node->next = (*stack);
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*top_from;

	if (!from || !(*from))
		return ;
	top_from = *from;
	*from = top_from->next;
	if (*from)
		(*from)->prev = NULL;
	top_from->next = *to;
	if (*to)
		(*to)->prev = top_from;
	*to = top_from;
}
