#include "push_swap.h"

t_args  *creat_list(int size)
{
    t_args  *ret;
    t_args  *head;
    int i;

    i = 0;
    if (!(ret = malloc(sizeof(t_args))))
        return (NULL);
    head = ret;
    while (i < size)
    {
        if (!(ret->next = malloc(sizeof(t_args))))
            return (NULL);
        ret->val = 0;
        ret = ret->next;
        ret->next = NULL;
        i++;
    }
    return (head);
}



int checkdata(char  *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            break;
        i++;
    }
    if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
        return (1);
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (ft_strlen(str + i) > 12)
            return (1);
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

int     is_duplicate(t_args  *list)
{
    t_args  *check;

    while (list->next)
    {
        check = list->next;
        while (check->next)
        {
            if (list->val == check->val)
                return (1);
            check = check->next;
        }
        list = list->next;
    }
    return (0);
}

int    dump_data(t_info    *info, char **argv)
{
    t_args  *tmp;
    int     i;

    i = 0;
    tmp = info->a;
    if (info->size > 0)
    {
        while (i < info->size)
        {
            if (checkdata(argv[i + 1]))
                return(0);
            tmp->val = ft_atoi(argv[i + 1]);
            if (tmp->val > INT32_MAX || tmp->val < INT32_MIN)
                return (0);
            tmp = tmp->next;
            i++;
        }
    }
    if (is_duplicate(info->a))
        return (0);
    return (1);
}

int     find_median(t_args  *list, int  size)
{
    int     swap;
    int     i;
    int     *arr;

    arr = malloc(size * sizeof(int));
    i = 0;
    while (i < size)
    {
        arr[i] = list->val;
        list = list->next;
        i++;
    }
    i = 0;
    while (i + 1 < size)
	{
		if (arr[i] <= arr[i + 1])
			i++;
		else
		{
			swap = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = swap;
			i = 0;
		}
	}
    return(arr[2]);
}