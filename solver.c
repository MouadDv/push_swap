#include "push_swap.h"

void    solver(t_info  *info)
{
    t_args *list;

    list = info->a;
    
    if (info->size <= 5)
        solve_less_5(info);
    else if (info->size <= 100)
        solve_less_100(info);
    else
        solve_above_100(info);
}