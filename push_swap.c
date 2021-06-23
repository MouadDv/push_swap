#include "push_swap.h"

int	chunk_end(int size, int min, t_info *info)
{
	int		i;
	int		*arr;
	int		ret;

	arr = arr_gen(info, info->a);
	i = 0;
	while (i < info->size)
	{
		if (arr[i] == min)
			break ;
		i++;
	}
	ret = arr[i + size - 1];
	free(arr);
	return (ret);
}

int	*arr_gen(t_info *info, t_args *list)
{
	int		i;
	int		*arr;
	int		swap;

	arr = malloc(info->size * sizeof(int));
	i = 0;
	while (i < info->size)
	{
		arr[i] = list->val;
		list = list->next;
		i++;
	}
	i = 0;
	while (i + 1 < info->size)
	{
		if (arr[i] > arr[i + 1])
		{
			swap = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = swap;
			i = -1;
		}
		i++;
	}
	return (arr);
}

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
