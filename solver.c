#include "push_swap.h"

void	free_allocated(t_info *info)
{
	t_args	*list;
	t_args	*tmp;

	list = info->a;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(info->b);
	free(info);
}

void	solver(t_info *info)
{
	if (info->size <= 5)
		solve_less_5(info);
	else if (info->size <= 100)
		solve_less_100(info, 0);
	else
		solve_above_100(info, 0);
	free_allocated(info);
}
