#ifndef SWAP_H
# define SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int		data;
	struct 	s_list *next;
} node;


typedef struct s_stack
{
	node *a;
	node *b;
	int original_size_of_a;
	int size_of_a;
	int size_of_b;
	int *arr;
	int *sorted_arr;
} t_stack;

void 	swap_nodes(node **head);
void	rotate(node **head);
void	rotate_reverse(node **head);
void	push_to_other(node **source, node **target);
void	push(node **top, int x);
int		ft_atoi(const char *nptr);
int 	get_size(node *head);
node 	*get_last_node(node *head);
int 	pop(node **pt);
void 	push_at_end(node **top, int x);
int 	get_last_data(node *top);
int 	get_min_val(node *top);
int 	get_max_val(node *top);
void 	display(node *head);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rrr(t_stack *stack);
int 	is_sorted(node *n);
int 	get_index(node *n, int i);
void 	next_under_pivot(node *n, int piv, int *first, int *last);
int 	less_than_pivot(node *n, int piv);
int 	decide_rotation(node *n, int piv, int size);
void 	sort_arr(int arr[], int low, int hi);


#endif