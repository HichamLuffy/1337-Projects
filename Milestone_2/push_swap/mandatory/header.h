/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:51:39 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/06 15:39:52 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_cost
{
	int	ra_count;
	int	rb_count;
	int	rra_count;
	int	rrb_count;
	int	total;
}	t_cost;

typedef struct s_subarrays
{
	int	*l;
	int	*r;
	int	n1;
	int	n2;
}	t_subarrays;

char	**ft_split(char *str, char *charset);
long	ft_atoi(const char *str);
void	move_to_b(t_stack **a, t_stack **b, int a_len);
int		ft_isdigit(int c);
int		stacksorted(t_stack *a);
t_stack	*ft_lstnew(int content);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	sort_3(t_stack **a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	assign_indices(t_stack *stack, int size);
void	insertion_sort(int *arr, int size);
void	merge_sort(int *arr, int left, int right);
void	sort_large_stack(t_stack **a, t_stack **b);
void	*ft_memset(void *b, int c, size_t len);
void	final_rotation(t_stack **a);
int		find_position(t_stack *stack, int index);
int		find_target_position(t_stack *a, int b_index);
t_stack	*get_node_at_position(t_stack *stack, int position);
void	execute_moves(t_stack **a, t_stack **b, t_cost cost);
void	fill_left(int *L, int *arr, int left, int n1);
void	fill_right(int *R, int *arr, int mid, int n2);
int		*copy_stack(int size, t_stack *stack);
void	merge(int *arr, int left, int mid, int right);
void	fill_a(t_stack **head, char **av);
void	dub_check(t_stack *a);
void	dis_error(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif