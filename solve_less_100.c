#include "push_swap.h"

void	push_chunk(t_info *info, int min, int max)
{
	int	top;
	int	buttom;

	top = top_possition(info->a, min, max);
	buttom = buttom_possition(info->a, min, max);
	if (top <= list_size(info->a) - buttom)
		while (info->a->val < min || info->a->val > max)
			ra(&info->a);
	else
		while (info->a->val < min || info->a->val > max)
			rra(&info->a);
	pb(&info->a, &info->b);
	info->size--;
}

int	chunckunfinished(t_args *list, int min, int max)
{
	while (list->next)
	{
		if (list->val >= min && list->val <= max)
			return (1);
		list = list->next;
	}
	return (0);
}

void	unload_b(t_info *info)
{
	int	top;
	int	largest;

	while (info->b->next != NULL)
	{
		largest = find_largest(info->b);
		top = top_possition(info->b, largest, largest);
		if (top <= list_size(info->b) / 2)
			while (info->b->val != largest)
				rb(&info->b);
		else
			while (info->b->val != largest)
				rrb(&info->b);
		pa(&info->a, &info->b);
	}
}

void	solve_less_100(t_info *info, int i)
{
	int	chunks;
	int	chunkend;
	int	chunkstart;
	int	smallest;
	int	largest;

	chunks = info->size / 5;
	largest = find_largest(info->a);
	while (i < 5)
	{
		smallest = find_smallest(info->a);
		chunkstart = smallest;
		if (i < 4)
		{
			chunkend = chunk_end(chunks, smallest, info);
			while (chunckunfinished(info->a, chunkstart, chunkend))
				push_chunk(info, chunkstart, chunkend);
			chunkstart = chunkend;
		}
		else
			while (chunckunfinished(info->a, chunkstart, largest + 1))
				push_chunk(info, chunkstart, largest + 1);
		i++;
	}
	unload_b(info);
}

void	solve_above_100(t_info *info, int i)
{
	int	chunks;
	int	chunkend;
	int	chunkstart;
	int	smallest;
	int	largest;

	chunks = info->size / 12;
	largest = find_largest(info->a);
	while (i < 12)
	{
		smallest = find_smallest(info->a);
		chunkstart = smallest;
		if (i < 11)
		{
			chunkend = chunk_end(chunks, smallest, info);
			while (chunckunfinished(info->a, chunkstart, chunkend))
				push_chunk(info, chunkstart, chunkend);
			chunkstart = chunkend;
		}
		else
			while (chunckunfinished(info->a, chunkstart, largest + 1))
				push_chunk(info, chunkstart, largest + 1);
		i++;
	}
	unload_b(info);
}
