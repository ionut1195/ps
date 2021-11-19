/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:47:40 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:36 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_int(char *p)
{
	int	i;

	i = 0;
	if (p[i] == '+' || p[i] == '-')
		i++;
	while (p[i])
	{
		if (!is_digit(p[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_node *n, long v)
{
	t_node	*c;

	if (n == NULL)
		return (0);
	c = n;
	while (c)
	{
		if (c->data == v)
			return (1);
		c = c->next;
	}
	return (0);
}

int	is_int_range(long n)
{
	if (n <= INT_MAX && n >= INT_MIN)
		return (1);
	return (0);
}

int	is_valid(t_node *t_node, char *c)
{
	if ((!is_int(c) || is_duplicate(t_node, ft_atoi(c))
			|| !is_int_range(ft_atoi(c))))
		return (0);
	return (1);
}
