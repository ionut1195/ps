/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:51:40 by itomescu          #+#    #+#             */
/*   Updated: 2021/11/19 08:49:31 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(long arr[], long low, long hi)
{
	long	s;
	long	e;
	long	temp;

	if (low > hi)
		return ;
	s = low;
	e = hi;
	while (s <= e)
	{
		while (arr[s] < arr[s + (e - s) / 2])
			s++;
		while (arr[e] > arr[s + (e - s) / 2])
			e--;
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
