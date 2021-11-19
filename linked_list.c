/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:50:58 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:22 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **top, int x)
{
	t_node	*nod;

	nod = (t_node *)malloc(sizeof(t_node));
	if (nod == NULL)
	{
		free(nod);
		exit (0);
	}
	nod->data = x;
	nod->next = *top;
	*top = nod;
}

int	get_size(t_node *head)
{
	int		i;
	t_node	*curr;

	curr = head;
	i = 0;
	while (curr != NULL)
	{
		i++;
		if (curr->next == NULL)
			return (i);
		curr = curr->next;
	}
	return (i);
}

t_node	*get_last_node(t_node *head)
{
	t_node	*temp;

	temp = head;
	if (temp == 0)
		return (0);
	while (temp)
	{
		if (temp->next == 0)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

int	pop(t_node **pt)
{	
	t_node	*n;
	int		i;

	n = *pt;
	i = (*pt)->data;
	*pt = (*pt)->next;
	free(n);
	return (i);
}

void	push_at_end(t_node **top, int x)
{
	t_node	*nod;
	t_node	*last;

	nod = (t_node *)malloc(sizeof(t_node));
	if (nod == NULL)
	{
		free(nod);
		exit (0);
	}
	nod->data = x;
	nod->next = NULL;
	if (*top == NULL)
		*top = nod;
	else
	{
		last = get_last_node(*top);
		last->next = nod;
	}
}
