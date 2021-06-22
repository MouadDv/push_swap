#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_args
{
	long long		val;
	struct s_args	*next;
}					t_args;

typedef struct		s_info
{
	int				size;
	t_args			*a;
	t_args			*b;
}					t_info;


t_args  *creat_list(int size);
int    dump_data(t_info    *info, char **argv);

void    sa(t_args **a);
void    sb(t_args **b);
void    ss(t_args **a, t_args **b);
void    pa(t_args **a, t_args **b);
void    pb(t_args **a, t_args **b);
void    ra(t_args **a);
void    rb(t_args **b);
void    rr(t_args **a, t_args **b);
void    rra(t_args **a);
void    rrb(t_args **b);
void    rrr(t_args **a, t_args **b);

void    solver(t_info  *info);
void    solve_less_100(t_info *info);
void    solve_above_100(t_info *info);

void    solve_less_5(t_info  *info);
void    solve_two(t_args **a);
void    solve_three(t_args **a);
int     find_median(t_args  *list, int  size);



void    printlist(t_args *list);


#endif
