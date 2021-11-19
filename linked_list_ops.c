/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:05 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:20 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_node **head)
{
	t_node	*temp;
	t_node	*third;

	if (*head && (*head)->next)
	{
		if ((*head)->next->next)
			third = (*head)->next->next;
		temp = *head;
		*head = (*head)->next;
		(*head)->next = temp;
		if (third)
			temp->next = third;
		else
			temp->next = NULL;
	}
}

void	rotate(t_node **head)
{
	t_node	*first;

	if (*head && (*head)->next)
	{
		first = (*head)->next;
		(get_last_node(*head))->next = *head;
		(*head)->next = NULL;
		*head = first;
	}
}

void	rotate_reverse(t_node **head)
{
	t_node	*last;
	t_node	*ante;

	if (*head && (*head)->next)
	{
		ante = *head;
		while ((ante->next)->next)
			ante = ante->next;
		last = ante->next;
		ante->next = NULL;
		last->next = *head;
		*head = last;
	}
}

void	push_to_other(t_node **source, t_node **target)
{
	if (*source == NULL)
		return ;
	push(target, pop(source));
}

void	free_stack(t_stack *s)
{
	t_node	*curr;

	curr = s->a;
	while (curr)
	{
		curr = curr->next;
		free(s->a);
		s->a = curr;
	}
	curr = s->b;
	while (curr)
	{
		curr = curr->next;
		free(s->b);
		s->b = curr;
	}
	free(s->sorted_arr);
}
