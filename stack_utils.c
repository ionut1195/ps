/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:00:37 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:34 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refill_a(t_stack *s)
{
	while (s->b)
		ft_pa(s);
}

void	refill_correct(t_stack *s)
{
	int	big;

	while (s->b)
	{
		big = get_max_val(s->b);
		if (get_index(s->b, big) <= (s->size_of_b / 2))
		{
			while (s->b->data != big)
				ft_rb(s);
		}
		else
		{
			while (s->b->data != big)
				ft_rrb(s);
		}
		ft_pa(s);
	}
}

void	init_stack(t_stack *s, int size)
{
	long	*s_ar;

	s->a = NULL;
	s->b = NULL;
	s_ar = (long *)malloc((sizeof(long) * (size)));
	s->sorted_arr = s_ar;
	s->size_of_a = size;
	s->size_of_b = 0;
	s->original_size_of_a = size;
}

void	choose_algo(t_stack *s, int size)
{
	if (size > 4 && size <= 10)
		sort_10(s);
	else if (size > 10 && size <= 100)
		push_swap(s, 4);
	else if (size > 100)
		push_swap(s, 8);
	else
		sort_3(s);
}
