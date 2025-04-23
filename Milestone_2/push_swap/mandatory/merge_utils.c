/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:29:57 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/03 16:12:51 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*copy_stack(int size, t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		*array;

	array = malloc(sizeof(int) * size);
	i = 0;
	tmp = stack;
	while (i < size)
	{
		array[i++] = tmp->data;
		tmp = tmp->next;
	}
	return (array);
}

void	merge_sorted(t_subarrays subs, int k, int *arr)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < subs.n1 && j < subs.n2)
	{
		if (subs.l[i] <= subs.r[j])
			arr[k++] = subs.l[i++];
		else
			arr[k++] = subs.r[j++];
	}
	while (i < subs.n1)
		arr[k++] = subs.l[i++];
	while (j < subs.n2)
		arr[k++] = subs.r[j++];
}

void	merge(int *arr, int left, int mid, int right)
{
	t_subarrays	subs;

	subs.n1 = mid - left + 1;
	subs.n2 = right - mid;
	subs.l = malloc(subs.n1 * sizeof(int));
	subs.r = malloc(subs.n2 * sizeof(int));
	if (!subs.l || !subs.r)
	{
		free(subs.l);
		free(subs.r);
		return ;
	}
	fill_left(subs.l, arr, left, subs.n1);
	fill_right(subs.r, arr, mid, subs.n2);
	merge_sorted(subs, left, arr);
	free(subs.l);
	free(subs.r);
}
