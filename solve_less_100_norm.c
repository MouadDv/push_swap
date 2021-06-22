#include "push_swap.h"

int	list_size(t_args *list)
{
	int	ret;

	ret = 0;
	while (list->next)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}

int	find_largest(t_args *list)
{
	int	ret;

	ret = INT32_MIN;
	while (list->next)
	{
		if (list->val > ret)
			ret = list->val;
		list = list->next;
	}
	return (ret);
}

int	find_smallest(t_args *list)
{
	int	ret;

	ret = INT32_MAX;
	while (list->next)
	{
		if (list->val < ret)
			ret = list->val;
		list = list->next;
	}
	return (ret);
}

int	top_possition(t_args *list, int min, int max)
{
	int	ret;

	ret = 0;
	while (list->next)
	{
		ret++;
		if (list->val >= min && list->val <= max)
			break ;
		list = list->next;
	}
	return (ret);
}

int	buttom_possition(t_args *list, int min, int max)
{
	int	temp;
	int	ret;

	ret = 0;
	temp = 0;
	while (list->next)
	{
		temp++;
		if (list->val >= min && list->val <= max)
			ret = temp;
		list = list->next;
	}
	return (ret);
}
