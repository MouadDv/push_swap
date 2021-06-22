#include "push_swap.h"

void	sa(t_args **a)
{
	int	swap;

	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	swap = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = swap;
	write(1, "sa\n", 3);
}

void	sb(t_args **b)
{
	int	swap;

	if ((*b)->next == NULL || (*b)->next->next == NULL)
		return ;
	swap = (*b)->val;
	(*b)->val = (*b)->next->val;
	(*b)->next->val = swap;
	write(1, "sb\n", 3);
}

void	pa(t_args **a, t_args **b)
{
	t_args	*tmp;

	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_args **a, t_args **b)
{
	t_args	*tmp;

	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_args **a)
{
	t_args	*tmp;
	t_args	*swap;
	t_args	*cp;

	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	swap = tmp->next;
	cp = (*a)->next;
	tmp->next = *a;
	(*a)->next = swap;
	*a = cp;
	write(1, "ra\n", 3);
}
