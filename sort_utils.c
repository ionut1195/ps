/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:35 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:33 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *n)
{
	if (!n)
		return (-1);
	if (n->next == NULL)
		return (1);
	while (n && n->next)
	{
		if (n->data < n->next->data)
			n = n->next;
		else
			return (0);
	}
	return (1);
}

int	get_index(t_node *n, int i)
{
	int	index;

	index = 0;
	if (!n)
		return (-1);
	while (n)
	{
		if (n->data == i)
			return (index);
		else
		{
			n = n->next;
			index++;
		}
	}
	return (-1);
}

void	next_under_pivot(t_node *n, int piv, int *first, int *last)
{
	int	idx;

	idx = 0;
	while (n)
	{
		if (n->data < piv)
			break ;
		n = n->next;
		(*first)++;
		idx++;
	}
	if (!n)
		*last = idx;
	while (n)
	{
		if (n->data < piv)
			*last = idx;
		n = n->next;
		idx++;
	}
}

int	less_than_pivot(t_node *n, int piv)
{
	while (n)
	{
		if (n->data < piv)
			return (1);
		n = n->next;
	}
	return (0);
}

void	decide_rotation_and_rotate(t_stack *s, int piv)
{
	int	first;
	int	last;

	first = 0;
	last = 0;
	next_under_pivot(s->a, piv, &first, &last);
	if (first <= (s->size_of_a - last - 1))
		while (s->a->data >= piv)
			ft_ra(s);
	else
		while (s->a->data >= piv)
			ft_ra(s);
}
