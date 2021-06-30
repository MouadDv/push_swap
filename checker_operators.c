#include "push_swap.h"

void	sa(t_args **a)
{
	int	swap;

	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	swap = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = swap;
}

void	sb(t_args **b)
{
	int	swap;

	if ((*b)->next == NULL || (*b)->next->next == NULL)
		return ;
	swap = (*b)->val;
	(*b)->val = (*b)->next->val;
	(*b)->next->val = swap;
}

void	pa(t_args **a, t_args **b)
{
	t_args	*tmp;

	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pb(t_args **a, t_args **b)
{
	t_args	*tmp;

	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = *b;
	*b = tmp;
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
}
