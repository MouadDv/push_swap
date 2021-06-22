#include "push_swap.h"

void    solve_four(t_info  *info)
{
    int i;
    int smallest;
    t_args *l;

    l = info->a;
    i = 0;
    smallest = INT32_MAX;
    while (i < info->size)
    {
        if (l->val < smallest)
            smallest = l->val;
        l = l->next;
        i++;
    }
    i = 0;
    while (i < info->size)
    {
        if (info->a->val != smallest)
            ra(&info->a);
        else
        {
            pb(&info->a, &info->b);
            break;
        }
        i++;
    }
    solve_three(&info->a);
    pa(&info->a, &info->b);
}

void    solve_five(t_info  *info)
{
    int i;
    int trig;
    int median;

    median = find_median(info->a, info->size);
    i = 0;
    trig = 0;
    while (i < info->size)
    {
        if (info->a->val < median)
        {
            pb(&info->a, &info->b);
            trig++;
        }
        else
            ra(&info->a);
        if (trig == 2)
            break;
        i++;
    }
    if (info->b->val < info->b->next->val)
        sb(&info->b);
    solve_three(&info->a);
    pa(&info->a, &info->b);
    pa(&info->a, &info->b);
}

void    solve_three(t_args **a)
{
    t_args *l;

    l = *a;
    if (l->val < l->next->val && l->val > l->next->next->val)
        rra(a);
    else if (l->val > l->next->val && l->val < l->next->next->val)
        sa(a);
    else if (l->val > l->next->val && l->val > l->next->next->val)
    {
        ra(a);
        if ((*a)->val > (*a)->next->val)
            sa(a);
    }
    else if (l->val < l->next->val && l->val < l->next->next->val)
    {
        if (l->next->val > l->next->next->val)
        {
            rra(a);
            sa(a);
        }
    }
}

void    solve_two(t_args **a)
{
    t_args *list;

    list = *a;
    if (list->val > list->next->val)
        sa(a);
}

void    solve_less_5(t_info  *info)
{
    if (info->size == 2)
        solve_two(&info->a);
    else if (info->size == 3)
        solve_three(&info->a);
    else if (info->size == 5)
        solve_five(info);
    else if (info->size == 4)
        solve_four(info);
}