/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:54:42 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/07 15:55:29 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_singl_line(char *ops)
{
	if (!ft_strcmp(ops, "sa\n"))
		return (1);
	else if (!ft_strcmp(ops, "sb\n"))
		return (1);
	else if (!ft_strcmp(ops, "ss\n"))
		return (1);
	else if (!ft_strcmp(ops, "ra\n"))
		return (1);
	else if (!ft_strcmp(ops, "rb\n"))
		return (1);
	else if (!ft_strcmp(ops, "rr\n"))
		return (1);
	else if (!ft_strcmp(ops, "rra\n"))
		return (1);
	else if (!ft_strcmp(ops, "rrb\n"))
		return (1);
	else if (!ft_strcmp(ops, "rrr\n"))
		return (1);
	else
		return (0);
	return (1);
}

int	check_instructions(char *ops)
{
	if (check_singl_line(ops))
		return (1);
	else if (!ft_strcmp(ops, "pa\n"))
		return (1);
	else if (!ft_strcmp(ops, "pb\n"))
		return (1);
	else
		return (0);
}
