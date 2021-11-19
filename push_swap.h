/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:26 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:39 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		original_size_of_a;
	int		size_of_a;
	int		size_of_b;
	long	*sorted_arr;
}	t_stack;

void	swap_nodes(t_node **head);
void	rotate(t_node **head);
void	rotate_reverse(t_node **head);
void	push_to_other(t_node **source, t_node **target);
void	push(t_node **top, int x);
void	init_stack(t_stack *s, int size);
long	ft_atoi(const char *nptr);
int		get_size(t_node *head);
t_node	*get_last_node(t_node *head);
int		pop(t_node **pt);
void	push_at_end(t_node **top, int x);
int		get_min_val(t_node *top);
int		get_max_val(t_node *top);
void	free_stack(t_stack *s);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rrr(t_stack *stack);
int		is_sorted(t_node *n);
int		get_index(t_node *n, int i);
void	next_under_pivot(t_node *n, int piv, int *first, int *last);
int		less_than_pivot(t_node *n, int piv);
void	decide_rotation_and_rotate(t_stack *s, int piv);
void	sort_arr(long arr[], long low, long hi);
void	refill_a(t_stack *s);
void	sort_3(t_stack *s);
void	sort_10(t_stack *s);
void	sort_last_chunk(t_stack *s);
void	refill_correct(t_stack *s);
void	choose_algo(t_stack *s, int size);
void	push_swap(t_stack *s, int div);
int		is_int_range(long n);
int		is_duplicate(t_node *n, long v);
int		is_int(char *p);
int		is_digit(char c);
int		is_valid(t_node *t_node, char *c);
int		error(t_stack *s);

#endif