#include "swap.h"

void	ft_sa(t_stack *stack)
{
	swap_nodes(&stack->a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack)
{
	swap_nodes(&stack->b);
	write(1, "sb\n", 3);
}

void	ft_pa(t_stack *stack)
{
	push_to_other(&stack->b, &stack->a); // source, target
	stack->size_of_a++;
	stack->size_of_b--;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *stack)
{
	push_to_other(&stack->a, &stack->b);
	stack->size_of_a--;
	stack->size_of_b++;
	write(1, "pb\n", 3);
}
void	ft_ra(t_stack *stack)
{
	rotate(&stack->a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *stack)
{
	rotate(&stack->b);
	write(1, "rb\n", 3);
}

void	ft_rra(t_stack *stack)
{
	rotate_reverse(&stack->a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack)
{
	rotate_reverse(&stack->b);
	write(1, "rrb\n", 4);
}
void	ft_ss(t_stack *stack)
{
	swap_nodes(&stack->a);
	swap_nodes(&stack->b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack *stack)
{
	rotate_reverse(&stack->a);
	rotate_reverse(&stack->b);
	write(1, "rrr\n", 4);
}