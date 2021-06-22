#include "push_swap.h"

int	is_sorted(t_args *a)
{
	while (a->next->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc > 1)
	{
		info = malloc(sizeof(t_info));
		if (info == NULL)
			return (1);
		info->size = argc - 1;
		info->a = creat_list(info->size);
		info->b = malloc(sizeof(t_args));
		info->b->next = NULL;
		if (!dump_data(info, argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (is_sorted(info->a))
			return (0);
		solver(info);
		return (0);
	}
	return (1);
}
