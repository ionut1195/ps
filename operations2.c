/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:43:01 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:25 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack)
{
	rotate_reverse(&stack->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack)
{
	rotate_reverse(&stack->b);
	write(1, "rrb\n", 4);
}

void	ft_ss(t_stack *stack)
{
	swap_nodes(&stack->a);
	swap_nodes(&stack->b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack *stack)
{
	rotate_reverse(&stack->a);
	rotate_reverse(&stack->b);
	write(1, "rrr\n", 4);
}
