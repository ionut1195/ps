#include "swap.h"

void push(node **top, int x)
{
    node *nod;
    nod = (node *)malloc(sizeof(node));
    if (nod == NULL)
        exit (0);
    nod->data = x;
    nod->next = *top;
    *top = nod;
}

int get_size(node *head)
{
    int i;
    node *curr;
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
node *get_last_node(node *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
}

int pop(node **pt)
{	
	node *next_node;
	int i;

	next_node = (*pt)->next;
	i = (*pt)->data;
	free(*pt);
	*pt = next_node;
	return(i);
}

void push_at_end(node **top, int x)
{
	node *nod;
	node *last;

	nod = (node *)malloc(sizeof(node));
	if (nod == NULL)
		exit (0);
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

