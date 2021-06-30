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
	if (a->next == NULL)
		return (0);
	while (a->next->next)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}

void	rrr(t_args **a, t_args **b)
{
	rra(a);
	rrb(b);
}
