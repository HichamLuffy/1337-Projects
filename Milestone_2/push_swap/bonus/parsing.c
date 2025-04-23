/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:17:42 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/07 13:42:49 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			if ((str[i] == '-' || str[i] == '+'))
			{
				if (i > 0 && str[i - 1] != ' ')
					dis_error(NULL);
				if (!ft_isdigit(str[i + 1]))
					dis_error(NULL);
			}
			else if (str[i] != ' ')
			{
				dis_error(NULL);
			}
		}
		i++;
	}
}

void	dub_check(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*current;
	int		j;

	tmp = a;
	while (tmp)
	{
		current = tmp;
		j = 0;
		while (current)
		{
			if (tmp->data == current->data)
				j++;
			current = current->next;
		}
		if (j >= 2)
			dis_error(&a);
		tmp = tmp->next;
	}
}

void	validate_and_add_number(t_stack **head, \
									t_stack **current, char *num_str)
{
	long	x;
	t_stack	*new_node;

	only_numbers(num_str);
	x = ft_atoi(num_str);
	if (x > INT_MAX || x < INT_MIN)
		dis_error(head);
	new_node = ft_lstnew(x);
	if (*head == NULL)
	{
		*head = new_node;
		*current = new_node;
	}
	else
	{
		(*current)->next = new_node;
		new_node->prev = *current;
		*current = new_node;
	}
}

void	process_numbers(t_stack **head, t_stack **current, char *arg)
{
	char	**numbers;
	int		j;

	numbers = ft_split(arg, " ");
	if (numbers == NULL || numbers[0] == NULL)
		dis_error(head);
	j = 0;
	while (numbers[j])
	{
		validate_and_add_number(head, current, numbers[j]);
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

void	fill_a(t_stack **head, char **av)
{
	t_stack	*current;
	int		i;

	current = NULL;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			dis_error(head);
		process_numbers(head, &current, av[i]);
		i++;
	}
}
