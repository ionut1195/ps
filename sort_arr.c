/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:40 by itomescu          #+#    #+#             */
/*   Updated: 2021/12/27 14:57:39 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_s(long *ar, long *s, long pivot)
{
	while (ar[*s] < pivot)
		(*s)++;
}
void	decrement_e(long *ar, long *e, long pivot)
{
	while (ar[*e] > pivot)
		(*e)--;
}

void	sort_arr(long arr[], long low, long hi)
{
	long	s;
	long	e;
	long	temp;
	long	pivot;

	if (low > hi)
		return ;
	s = low;
	e = hi;
	pivot = arr[s + (e - s) / 2];
	while (s <= e)
	{
		increment_s(arr, &s, pivot);
		decrement_e(arr, &e, pivot);
		if (s <= e)
		{
			temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;
			e--;
		}
		sort_arr(arr, low, e);
		sort_arr(arr, s, hi);
	}
}
