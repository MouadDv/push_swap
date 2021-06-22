#include "push_swap.h"

int     list_size(t_args *list)
{
    int ret;

    ret = 0;
    while (list->next)
    {
        ret++;
        list = list->next;
    }
    return (ret);
}

int     find_largest(t_args *list)
{
    int ret;

    ret = INT32_MIN;
    while (list->next)
    {
        if (list->val > ret)
            ret = list->val;
        list = list->next;
    }
    return (ret);
}

int     find_smallest(t_args *list)
{
    int ret;

    ret = INT32_MAX;
    while (list->next)
    {
        if (list->val < ret)
            ret = list->val;
        list = list->next;
    }
    return (ret);
}

int     top_possition(t_args *list, int min, int max)
{
    int     ret;

    ret = 0;
    while (list->next)
    {
        ret++;
        if (list->val >= min && list->val <= max)
            break;
        list = list->next;
    }
    return (ret);
}

int     buttom_possition(t_args *list, int min, int max)
{
    int     temp;
    int     ret;

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

void    push_chunk(t_info *info, int min, int max)
{
    int top;
    int buttom;

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

int     chunckunfinished(t_args *list, int min, int max)
{
    while (list->next)
    {
        if (list->val >= min && list->val <= max)
            return (1);
        list = list->next;
    }
    return (0);
}

void    unload_b(t_info *info)
{
    int top;
    int largest;

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

int     chunk_end(int size, int min, t_info *info)
{
    int     swap;
    int     i;
    int     *arr;
    t_args  *list;
    int     ret;

    list = info->a;
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
    i = 0;
    while (arr[i])
    {
        if (arr[i] == min)
            break;
        i++;
    }
    ret = arr[i + size - 1];
    free(arr);
    return (ret);
}

void    solve_less_100(t_info *info)
{
    int chunks;
    int chunkend;
    int chunkstart;
    int smallest;
    int largest;
    int i;

    i = 0;
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

void    solve_above_100(t_info *info)
{
    int chunks;
    int chunkend;
    int chunkstart;
    int smallest;
    int largest;
    int i;

    i = 0;
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
        {
            while (chunckunfinished(info->a, chunkstart, largest + 1))
                push_chunk(info, chunkstart, largest + 1);
        }
        i++;
    }
    unload_b(info);
}