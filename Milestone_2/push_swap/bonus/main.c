/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:48:46 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/07 16:16:53 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	handle_single_stack(char *ops, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(ops, "sa\n"))
		sa(a);
	else if (!ft_strcmp(ops, "sb\n"))
		sb(b);
	else if (!ft_strcmp(ops, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(ops, "ra\n"))
		ra(a);
	else if (!ft_strcmp(ops, "rb\n"))
		rb(b);
	else if (!ft_strcmp(ops, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(ops, "rra\n"))
		rra(a);
	else if (!ft_strcmp(ops, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(ops, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	apply_instructions(char *ops, t_stack **a, t_stack **b)
{
	if (handle_single_stack(ops, a, b))
		return ;
	else if (!ft_strcmp(ops, "pa\n"))
		pa(b, a);
	else if (!ft_strcmp(ops, "pb\n"))
		pb(a, b);
	else
		stop_error(a, b);
}

t_list	*read_instructions(t_stack **a)
{
	t_list	*instructions;
	char	*line;

	instructions = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (check_instructions(line) == 0)
		{
			free(line);
			write(2, "Error\n", 6);
			ft_lstclear(a);
			exit(1);
		}
		ft_instadd_back(&instructions, ft_instnew(ft_strdup(line)));
		free(line);
		line = get_next_line(0);
	}
	return (instructions);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;
	t_list	*current;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	fill_a(&a, av);
	dub_check(a);
	instructions = read_instructions(&a);
	current = instructions;
	while (current)
	{
		apply_instructions(current->content, &a, &b);
		current = current->next;
	}
	if (stacksorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	cleanup(&instructions, &a, &b);
	return (1);
}
