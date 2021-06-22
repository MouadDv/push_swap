#include "push_swap.h"

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
	write(1, "rb\n", 3);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	solver(t_info *info)
{
	if (info->size <= 5)
		solve_less_5(info);
	else if (info->size <= 100)
		solve_less_100(info);
	else
		solve_above_100(info);
}
