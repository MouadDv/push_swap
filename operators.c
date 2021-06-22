#include "push_swap.h"

void    sa(t_args **a)
{
    int swap;

    if ((*a)->next == NULL || (*a)->next->next == NULL)
        return ;
    swap = (*a)->val;
    (*a)->val = (*a)->next->val;
    (*a)->next->val = swap;
    printf("sa\n");
}

void    sb(t_args **b)
{
    int swap;

    if ((*b)->next == NULL || (*b)->next->next == NULL)
        return ;
    swap = (*b)->val;
    (*b)->val = (*b)->next->val;
    (*b)->next->val = swap;
    printf("sb\n");
}

void    ss(t_args **a, t_args **b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}

void    pa(t_args **a, t_args **b)
{
    t_args  *tmp;

    tmp = *b;
    (*b) = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    printf("pa\n");
}

void    pb(t_args **a, t_args **b)
{
    t_args  *tmp;

    tmp = *a;
    (*a) = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    printf("pb\n");
}

void    ra(t_args **a)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;
    t_args  *end;

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
    printf("ra\n");
}

void    rb(t_args **b)
{
    t_args  *tmp;
    t_args  *swap;
    t_args  *cp;
    t_args  *end;

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
    printf("rb\n");
}

void    rr(t_args **a, t_args **b)
{
    ra(a);
    rb(b);
    printf("rr\n");
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

    printf("rra\n");
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

    printf("rrb\n");
}

void    rrr(t_args **a, t_args **b)
{
    rra(a);
    rrb(b);
    printf("rrr\n");
}