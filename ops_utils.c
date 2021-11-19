/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:45:47 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:26 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack *stack)
{
	rotate(&stack->b);
	write(1, "rb\n", 3);
}

int	error(t_stack *s)
{
	write(2, "Error\n", 6);
	free_stack(s);
	return (-1);
}
