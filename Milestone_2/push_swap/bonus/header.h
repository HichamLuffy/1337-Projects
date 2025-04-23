/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:51:39 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/07 14:04:18 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		check_instructions(char *ops);
void	ft_instclear(t_list **lst, void (*del)(void *));
void	ft_instadd_back(t_list **lst, t_list *new_node);
t_list	*ft_instnew(char *content);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*fill_fix_line(char **buf, int len);
int		check_new_line(char *buf);
char	**ft_split(char *str, char *charset);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	cleanup(t_list **instructions, t_stack **a, t_stack **b);
int		stacksorted(t_stack *a);
t_stack	*ft_lstnew(int content);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	fill_a(t_stack **head, char **av);
void	dub_check(t_stack *a);
void	dis_error(t_stack **stack);
void	stop_error(t_stack **a, t_stack **b);
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