/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:35:03 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:28 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s)
{
	if ((s->a->data < s->a->next->data)
		&& (s->a->data < s->a->next->next->data))
	{
		ft_rra(s);
		ft_sa(s);
	}
	else if ((s->a->data > s->a->next->data)
		&& (s->a->next->data > s->a->next->next->data))
	{
		ft_ra(s);
		ft_sa(s);
	}
	else if ((s->a->data < s->a->next->data)
		&& (s->a->data > s->a->next->next->data))
		ft_rra(s);
	else if ((s->a->data > s->a->next->data)
		&& (s->a->data < s->a->next->next->data))
		ft_sa(s);
	else if ((s->a->data > s->a->next->data)
		&& (s->a->next->data < s->a->next->next->data))
		ft_ra(s);
}

void	sort_10(t_stack *s)
{
	int	proximity;
	int	idx;
	int	min;

	while (!is_sorted(s->a) && s->size_of_a > 3)
	{
		min = get_min_val(s->a);
		idx = get_index(s->a, min);
		proximity = s->size_of_a / 2;
		if (idx < proximity)
			while (s->a->data != min)
				ft_ra(s);
		else
			while (s->a->data != min)
				ft_rra(s);
		ft_pb(s);
	}
	if (!is_sorted(s->a))
		sort_3(s);
	refill_a(s);
}

void	sort_last_chunk(t_stack *s)
{
	int	proximity;
	int	idx;
	int	min;

	while (!is_sorted(s->a) && s->size_of_a > 3)
	{
		min = get_min_val(s->a);
		idx = get_index(s->a, min);
		proximity = s->size_of_a / 2;
		if (idx <= proximity)
			while (s->a->data != min)
				ft_ra(s);
		else
			while (s->a->data != min)
				ft_rra(s);
		ft_pb(s);
	}
	if (!is_sorted(s->a))
		sort_3(s);
}

void	push_swap(t_stack *s, int div)
{
	int	chunk;
	int	pivot;

	chunk = 1;
	while (!is_sorted(s->a) && s->size_of_a > 10 && chunk < div)
	{
		pivot = s->sorted_arr[((s->original_size_of_a / div) * chunk)];
		while (less_than_pivot(s->a, pivot))
		{
			if (s->a->data < pivot)
			{
				ft_pb(s);
				if (!less_than_pivot(s->a, pivot))
					break ;
			}
			decide_rotation_and_rotate(s, pivot);
			ft_pb(s);
			if (s->size_of_a <= 10)
				break ;
		}
		chunk++;
	}
	sort_last_chunk(s);
	refill_correct(s);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		i;

	init_stack(&stacks, argc - 1);
	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (is_valid(stacks.a, argv[i]))
			{
				push_at_end(&stacks.a, ft_atoi(argv[i]));
				*(stacks.sorted_arr + (i - 1)) = ft_atoi(argv[i]);
			}
			else
				return (error(&stacks));
			i++;
		}
	}
	sort_arr(stacks.sorted_arr, 0, argc - 2);
	choose_algo(&stacks, argc);
	free_stack(&stacks);
}
