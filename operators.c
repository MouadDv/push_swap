#include "push_swap.h"

void    sa(t_args **a)
{
    int swap;

    if ((*a)->next == NULL || (*a)->next->next == NULL)
        return ;
    swap = (*a)->val;
    (*a)->val = (*a)->next->val;
    (*a)->next->val = swap;
    write(1, "sa\n", 3);
}

void    sb(t_args **b)
{
    int swap;

    if ((*b)->next == NULL || (*b)->next->next == NULL)
        return ;
    swap = (*b)->val;
    (*b)->val = (*b)->next->val;
    (*b)->next->val = swap;
    write(1, "sb\n", 3);
}

void    ss(t_args **a, t_args **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void    pa(t_args **a, t_args **b)
{
    t_args  *tmp;

    tmp = *b;
    (*b) = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1, "pa\n", 3);
}

void    pb(t_args **a, t_args **b)
{
    t_args  *tmp;

    tmp = *a;
    (*a) = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, "pb\n", 3);
}

void    ra(t_args **a)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;

    if ((*a)->next == NULL || (*a)->next->next == NULL)
        return ;
    tmp = *a;
    while(tmp->next->next)
        tmp = tmp->next;
    swap = tmp->next;
    cp = (*a)->next;
    tmp->next = *a;
    (*a)->next = swap;
    *a = cp;
    write(1, "ra\n", 3);
}

void    rb(t_args **b)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;

    if ((*b)->next == NULL || (*b)->next->next == NULL)
        return ;
    tmp = *b;
    while(tmp->next->next)
        tmp = tmp->next;
    swap = tmp->next;
    cp = (*b)->next;
    tmp->next = *b;
    (*b)->next = swap;
    *b = cp;
    write(1, "rb\n", 3);
}

void    rr(t_args **a, t_args **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void    rra(t_args **a)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;
    t_args  *end;

    if ((*a)->next == NULL || (*a)->next->next == NULL)
        return ;
    tmp = *a;
    while(tmp->next->next)
    {
        if (tmp->next->next->next == NULL)
            swap = tmp;
        tmp = tmp->next;
    }
    end = tmp->next;
    cp = *a;
    *a = tmp;
    tmp->next = cp;
    swap->next = end;

    write(1, "rra\n", 4);
}

void    rrb(t_args **b)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;
    t_args  *end;

    if ((*b)->next == NULL || (*b)->next->next == NULL)
        return ;
    tmp = *b;
    while(tmp->next->next)
    {
        if (tmp->next->next->next == NULL)
            swap = tmp;
        tmp = tmp->next;
    }
    end = tmp->next;
    cp = *b;
    *b = tmp;
    tmp->next = cp;
    swap->next = end;

    write(1, "rrb\n", 4);
}

void    rrr(t_args **a, t_args **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}