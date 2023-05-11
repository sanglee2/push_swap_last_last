

#include "push_swap.h"

void    print_ra(t_deq *deq_a)
{
    rotate(deq_a);
    write(1, "ra\n", 3);
}

void    print_rra(t_deq *deq_a)
{
    r_rotate(deq_a);
    write(1, "rra\n", 4);
}

void    print_rb(t_deq *deq_b)
{
    rotate(deq_b);
    write(1, "rb\n", 3);
}

void    print_rrb(t_deq *deq_b)
{
    r_rotate(deq_b);
    write(1, "rrb\n", 4);
}

void    print_sa(t_deq *deq_a)
{
    swap(deq_a);
    write(1, "sa\n", 3);
}