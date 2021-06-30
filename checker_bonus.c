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
	list = info->b;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(info);
}

void	check(char	*line, t_info *info)
{
	if (!ft_strncmp(line, "pa", 3))
		pa(&info->a, &info->b);
	else if (!ft_strncmp(line, "pb", 3))
		pb(&info->a, &info->b);
	else if (!ft_strncmp(line, "ra", 3))
		ra(&info->a);
	else if (!ft_strncmp(line, "rb", 3))
		rb(&info->b);
	else if (!ft_strncmp(line, "rr", 3))
		rr(&info->a, &info->b);
	else if (!ft_strncmp(line, "rra", 4))
		rra(&info->a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(&info->b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(&info->a, &info->b);
	else
	{
		write (2, "Error\n", 6);
		free_allocated(info);
		exit(0);
	}
}

void	checker(t_info *info)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, "sa", 3))
			sa(&info->a);
		else if (!ft_strncmp(line, "sb", 3))
			sb(&info->b);
		else if (!ft_strncmp(line, "ss", 3))
			ss(&info->a, &info->b);
		else
			check(line, info);
		free(line);
	}
	free(line);
	if (is_sorted(info->a) && list_size(info->b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
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
			free_allocated(info);
			return (1);
		}
		checker(info);
		free_allocated(info);
		return (0);
	}
	return (1);
}
