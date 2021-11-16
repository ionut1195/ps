#include "swap.h"

int get_last_data(node *top)
{
	node *curr;

	if (top)
		curr = top;
	while (curr)
	{
		if (curr->next)
			curr = curr->next;
		else
			break;
	}
	return (curr->data);
}

int get_min_val(node *top)
{
	int min;

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
int get_max_val(node *top)
{
	int max;

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