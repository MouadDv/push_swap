#include "push_swap.h"

int	*gen_arr(t_args *list, int size)
{
	int	*arr;
	int	i;

	arr = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = list->val;
		list = list->next;
		i++;
	}
	return (arr);
}

int	find_median(t_args *list, int size, int ret)
{
	int	swap;
	int	i;
	int	*arr;

	arr = gen_arr(list, size);
	i = 0;
	while (i + 1 < size)
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
	ret = arr[2];
	free(arr);
	return (ret);
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
