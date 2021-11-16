#include "swap.h"

void swap_nodes(node **head)
{
    node *temp;
	node *third;

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
void	rotate(node **head)
{
	node *first;

	if (*head && (*head)->next)
	{
		first = (*head)->next;
		(get_last_node(*head))->next = *head;
		(*head)->next = NULL;
		*head = first;
	}
}

void	rotate_reverse(node **head)
{
	node *curr;
	int value;

	curr = *head;
	while(curr->next->next != NULL)
		curr = curr->next;
	value = curr->next->data;
	curr->next = NULL;
	free(curr->next);
	push(head,value);
}

void	push_to_other(node **source, node **target)
{
	if (*source == NULL)
		return ;
	push(target,pop(source));
}

void display(node *head)
{
    node *curr;
    curr = head;
    if (curr != NULL)
    {
        while (curr != NULL)
        {
            printf("%d -> ",curr->data);
            curr = curr->next;
        }
    }
    else
        printf("s is empty");
}
