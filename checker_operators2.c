#include "push_swap.h"

void	ss(t_args **a, t_args **b)
{
	sa(a);
	sb(b);
}

void	rr(t_args **a, t_args **b)
{
	ra(a);
	rb(b);
}

void	rb(t_args **b)
{
	t_args	*tmp;
	t_args	*swap;
	t_args	*cp;

	if ((*b)->next == NULL || (*b)->next->next == NULL)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	swap = tmp->next;
	cp = (*b)->next;
	tmp->next = *b;
	(*b)->next = swap;
	*b = cp;
}

void	rra(t_args **a)
{
	t_args	*tmp;
	t_args	*swap;
	t_args	*cp;
	t_args	*end;

	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next)
	{
		if (tmp->next->next->next == NULL)
			swap = tmp;
		tmp = tmp->next;
	}
	end = tmp->next;
	cp = *a;
	*a = tmp;
	tmp->next = cp;
	swap->next = end;
}

void	rrb(t_args **b)
{
	t_args	*tmp;
	t_args	*swap;
	t_args	*cp;
	t_args	*end;

	if ((*b)->next == NULL || (*b)->next->next == NULL)
		return ;
	tmp = *b;
	while (tmp->next->next)
	{
		if (tmp->next->next->next == NULL)
			swap = tmp;
		tmp = tmp->next;
	}
	end = tmp->next;
	cp = *b;
	*b = tmp;
	tmp->next = cp;
	swap->next = end;
}
