/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:27 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/03 15:35:36 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_left(int *L, int *arr, int left, int n1)
{
	int	i;

	i = 0;
	while (i < n1)
	{
		L[i] = arr[left + i];
		i++;
	}
}

void	fill_right(int *R, int *arr, int mid, int n2)
{
	int	i;

	i = 0;
	while (i < n2)
	{
		R[i] = arr[mid + 1 + i];
		i++;
	}
}
