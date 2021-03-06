/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:50:38 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:19 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_val(t_node *top)
{
	int	min;

	if (!top)
		return (-1);
	min = top->data;
	while (top)
	{
		if (top->data < min)
			min = top->data;
		top = top->next;
	}
	return (min);
}

int	get_max_val(t_node *top)
{
	int	max;

	if (!top)
		return (-1);
	max = top->data;
	while (top)
	{
		if (top->data > max)
			max = top->data;
		top = top->next;
	}
	return (max);
}
