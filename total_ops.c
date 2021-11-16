#include <stdio.h>
#include <stdlib.h>
#include "sort.c"
#include <unistd.h>
#include "operations.c"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	itr;

	sign = 1;
	itr = 0;
	result = 0;
	while ((nptr[itr] >= 7 && nptr[itr] <= 13) || nptr[itr] == ' ')
		itr++;
	if (nptr[itr] == '-')
		sign = -1;
	if (nptr[itr] == '-' || nptr[itr] == '+')
		itr++;
	while (nptr[itr] >= '0' && nptr[itr] <= '9' && nptr[itr])
	{
		result = result * 10 + (nptr[itr] - '0');
		nptr++;
	}
	return (sign * result);
}

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

void swap_nodes(node **head)
{
    int size;
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

node *get_last_node(node *head)
{
	if (head)
	{
		while (head->next)
			head = head->next;
	}
	return (head);
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

void	push_to_other(node **source, node **target)
{
	if (*source == NULL)
		return ;
	push(target,pop(source));
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
	{
		push(top,x);
		free(nod);
	}
	else
	{
		last = get_last_node(*top);
		last->next = nod;
	}
}

int get_max_val(node *top)
{
	int max;

	if (!top)
		return (-1);
	max = top->data;
	while (top)
	{
		if (top->data < max)
			max = top->data;
		top = top->next;
	}
	return (max);
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

void refill_a(t_stack *s, int *ops)
{
	while (s->b)
		{
			(*ops)++;
			ft_pa(s);
		}
}

void sort_3(t_stack *s, int *ops)
{
	if ((s->a->data < s->a->next->data) && (s->a->next->data < s->a->next->next->data))// 1 2 3
		printf("Already sorted!");
	else if ((s->a->data < s->a->next->data) && (s->a->data < s->a->next->next->data))// 1 3 2
	{
		ft_rra(s);
		ft_sa(s);
		(*ops) += 2;
	}
	else if ((s->a->data > s->a->next->data) && (s->a->next->data > s->a->next->next->data))// 3 2 1
	{
		ft_ra(s);
		ft_sa(s);
		(*ops) += 2;
	}
	else if ((s->a->data < s->a->next->data) && (s->a->data > s->a->next->next->data)) // 2 3 1
		{
			ft_rra(s);
			(*ops)++;
		}
	else if ((s->a->data > s->a->next->data) && (s->a->data < s->a->next->next->data)) // 2 1 3
		{
			ft_sa(s);
			(*ops)++;
		}
	else if ((s->a->data > s->a->next->data) && (s->a->next->data < s->a->next->next->data)) // 3 1 2
	{
		ft_ra(s);
		(*ops)++;
	}
}
/*int get_index(int *arr, int i)
{
	int index;

	index = 0;
	if (!*arr)
		return -1;
	while (arr + index)
	{
		if (*(arr + index) == i)
			return (index);
		index++;
	}
}
*/
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
			n = n->next;
			index++;
	}
}

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

void sort_10(t_stack *s)
{
	int proximity;
	int idx;
	int min;
	int ops;

	ops = 0; 
	while(!is_sorted(s->a) && s->size_of_a > 3)
	{
		min = get_min_val(s->a);
		idx = get_index(s->a, min);
		proximity = s->size_of_a / 2;
		if (idx < proximity)
			while (s->a->data != min)
				{
					ft_ra(s);
					ops++;
				}
		else
			while (s->a->data != min)
				{
					ops++;
					ft_rra(s);
				}
		ft_pb(s);
		ops++;
	}
	if (!is_sorted(s->a))
		sort_3(s, &ops);
	refill_a(s, &ops);
	printf("total operations -- %d\n", ops);
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

void sort_last_chunk(t_stack *s, int *ops)
{
	int proximity;
	int idx;
	int min;

	while(!is_sorted(s->a) && s->size_of_a > 3)
	{
		min = get_min_val(s->a);
		idx = get_index(s->a, min);
		proximity = s->size_of_a / 2;
		if (idx <= proximity)
			while (s->a->data != min)
				{
					ft_ra(s);
					(*ops)++;
				}
		else
			while (s->a->data != min)
				{
					(*ops)++;
					ft_rra(s);
				}
		ft_pb(s);
		ops++;
	}
	if (!is_sorted(s->a))
		sort_3(s, ops);
}

void refill_correct(t_stack *s, int *ops)
{
	int big;

	while (s->b)
	{
		big = get_max_val(s->b);
		if (get_index(s->b, big) <= (s->size_of_b / 2))
		{
			while (s->b->data != big)
				{
					ft_rb(s);
					(*ops)++;
				}
		}
		else
		{
			while (s->b->data != big)
				{
					ft_rrb(s);
					(*ops)++;
				}
		}
		ft_pa(s);
		(*ops)++;
	}
}

void sort_100(t_stack *s)
{
	int chunk;
	int idx;
	int pivot;
	int ops;
	int itr;

	chunk = 1;
	ops = 0;
	while (!is_sorted(s->a) && s->size_of_a > 10 && chunk < 4)
	{
		pivot = s->sorted_arr[((s->original_size_of_a / 4) * chunk)];
		while (less_than_pivot(s->a, pivot))
		{
			if (s->a->data < pivot)
				{
					ft_pb(s);
					ops++;
					if (!less_than_pivot(s->a, pivot))
						break;
				}
			if (decide_rotation(s->a, pivot, s->size_of_a) == 1)
				while (s->a->data >= pivot)
					{
						ops++;
						ft_ra(s);
					}
			else
				while (s->a->data >= pivot)
					{
						ops++;
						ft_rra(s);
					}
			ft_pb(s);
			ops++;
			if (s->size_of_a <= 10)
				break;
		}
		chunk++;
	}
	sort_last_chunk(s, &ops);
	refill_correct(s, &ops);
}

void init_stack(t_stack *s, int size, int *ar, int *s_ar)
{
	s->a = NULL;
	s->b = NULL;
	s->arr = ar;
	s->sorted_arr = s_ar;
	s->size_of_a = size;
	s->size_of_b = 0;
	s->original_size_of_a = size;
}

int main(int argc, char **argv)
{
	int val;
	int *ar;
	int *s_ar;
	ar = (int *)malloc((sizeof(int) * (argc - 1)));
	s_ar = (int *)malloc((sizeof(int) * (argc - 1)));
	int ops = 0;
	t_stack stacks;
	int op = 0;
	init_stack(&stacks, argc - 1, ar, s_ar);
	int i = 1;
	int k = 0;
	if (argc >= 2){
		while (i < argc){
			val = ft_atoi(argv[i]);
			push_at_end(&stacks.a, val);
			*(ar + k) = val;
			*(s_ar + k) = val;
			i++;
			k++;
		}
	}
	//stacks.a_last = get_last_node(&top);

	//ft_solve(&stacks);
	sort_arr(stacks.sorted_arr,0, argc - 2);
	//push_swap(&stacks);
	//int ind = get_index(stacks.arr, 99);
	//sort_3(&stacks);
	//rotate(&stacks.a);
	//printf("the index is %d\n", ind);
	sort_100(&stacks);
	//rotate(&stacks.a);
	//printf("%d\n\n",stacks.size_of_a);
	printf("a -----\n");
	display(stacks.a);
	/*printf("\nb ----\n");
	display(stacks.b);
	printf("\n\n\n");
	for (int x=0; x<argc - 1; x++)
		printf("%d ",stacks.sorted_arr[x]);*/
	//printf("%d",stacks.a_last->data);
	/*node *top;
	node *b;
	t_stack stacks;
	init(&top);
	init(&b);

	push(&top,21);
	push(&top,1);
	push(&top,3);
	push(&top,51);
	push(&top,32);
	push(&top,7);

    push(&b,221);
	push(&b,11);
	push(&b,352);
	push(&b,44);
	push(&b,21);
	push(&b,3);
	//printf("\n%d\n",get_size(top));
	stacks.a = top;
	stacks.b = b;
	printf("   -  s a -- BEFORE\n");
	display(stacks.a);
	
	//printf("\n   -  s b -- BEFORE\n");
	//display(stacks.b);
	//swap_a(&top);
	//printf("\n%d\n",pop(&top));
	//push_to_other(&(stacks.a), &(stacks.b));
	printf("\n   -  s a -- AFTER\n");
	//rotate(&stacks.a);
	rotate_reverse(&stacks.a);
	rotate_reverse(&stacks.a);

	rotate_reverse(&stacks.a);
	display(stacks.a);
	printf("\n");
	//printf("   -  s b -- AFTER\n");
	//display(stacks.b);
	//display(stacks.b);
	//printf("%d", get_size(top));*/
}