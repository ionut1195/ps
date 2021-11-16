#include "swap.h"

int is_sorted(node *n)
{
	if (!n)
		return -1;
	if (n->next == NULL)
		return (1);
	while(n && n->next)
	{
		if (n->data < n->next->data)
			n = n->next;
		else
			return (0);
	}
	return (1);
}

int get_index(node *n, int i)
{
	int index;

	index = 0;
	if (!n)
		return -1;
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

void next_under_pivot(node *n, int piv, int *first, int *last)
{
	int idx;

	idx = 0;
	while(n)
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

int less_than_pivot(node *n, int piv)
{
	while(n)
	{
		if (n->data < piv)
			return (1);
		n = n->next;
	}
	return (0);
}

int decide_rotation(node *n, int piv, int size)
{
	int first;
	int last;

	first = 0;
	last = 0;
	next_under_pivot(n, piv, &first, &last);
	if (first <= (size - last - 1))
		return (1);// rotate
	return (2);// reverse rotate
}
