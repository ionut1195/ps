/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:14 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:23 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
{
	swap_nodes(&stack->a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack)
{
	swap_nodes(&stack->b);
	write(1, "sb\n", 3);
}

void	ft_pa(t_stack *stack)
{
	push_to_other(&stack->b, &stack->a);
	stack->size_of_a++;
	stack->size_of_b--;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack)
{
	push_to_other(&stack->a, &stack->b);
	stack->size_of_a--;
	stack->size_of_b++;
	write(1, "pb\n", 3);
}

void	ft_ra(t_stack *stack)
{
	rotate(&stack->a);
	write(1, "ra\n", 3);
}
