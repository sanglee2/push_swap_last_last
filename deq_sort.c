
#include"push_swap.h"
#include<limits.h>

// void sort_two_element(t_deq *deq_a)
// {
//     int *lst;

//     lst = deq_a->content;
//     if (lst > (lst + 1))
//         sa(deq_a);
//     return ;
// }


// 포인터로 접근이 지금 어려운 점
void sort_two_element(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;
    if (temp->content > temp->next->content)
        sa(deq_a);
    return ;
}


// void sort_three_element(t_deq *deq_a)
// {
//     int *lst;

//     lst = deq_a->content;
//     if (lst > (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) < lst)
//         sa(deq_a);
//     else if (lst < (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) > lst)
//     {
//         sa(deq_a);
//         rra(deq_a);
//     }
//     else if (lst > (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) > lst)
//         ra(deq_a);
//     else if (lst < (lst + 1) && (lst + 1) > (lst + 2) && (lst + 2) < lst)
//     {
//         sa(deq_a);
//         ra(deq_a);
//     }
//     else if (lst < (lst + 1) && (lst + 1) > (lst + 2) && (lst + 2) > lst)
//         rra(deq_a);
// }

void sort_three_element(t_deq *deq_a)
{
    t_node *temp;

    int first;
    int second;
    int third;

    temp = deq_a->a_top;
    if (temp->content > temp->next->content && 
    temp->next->content < temp->next->next->content &&
    temp->next->next->content > temp->content)
        sa(deq_a);
    else if (temp->content > temp->next->content &&
    temp->next->content > temp->next->next->content &&
    temp->next->next->content < temp->content)
    {
        sa(deq_a);
        rra(deq_a);
    }
    else if (temp->content > temp->next->content &&
    temp->next->content < temp->next->next->content &&
    temp->next->next->content < temp->content)
        ra(deq_a);
    else if (temp->content < temp->next->content &&
    temp->next->content > temp->next->next->content &&
    temp->next->next->content > temp->content)
    {
        sa(deq_a);
        ra(deq_a);
    }
    // 2 3 1
    else if (temp->content < temp->next->content &&
    temp->next->content > temp->next->next->content &&
    temp->next->next->content < temp->content)
        rra(deq_a);
}

void sort_four_element(t_deq* deq_a, t_deq* deq_b)
{
    t_deq *temp;
    int max;
    int min;
    int size;

    temp = deq_a;
    max = get_max_value(deq_a);
    min = get_min_value(deq_a);
    size = deq_a->a_size;

    while (temp->a_top->content && size > 3)
    {
        if (temp->a_top->index == max || temp->a_top->index == min)
            pa(deq_a, deq_b);
        else
            ra(deq_a);
        temp->a_top = temp->a_top->next;    
    }
    sort_three_element(deq_a);
    pa (deq_a, deq_b);
}

void sort_five_element(t_deq* deq_a, t_deq* deq_b)
{
    t_deq *temp;
    int max;
    int min;

    temp = deq_a;
    max = get_max_value(deq_a);
    min = get_min_value(deq_a);

    while (temp->a_top->content)
    {
        if (temp->a_top->index == max || temp->a_top->index == min)
            pa(deq_a, deq_b);
        else
            ra(deq_a);
        temp->a_top = temp->a_top->next; 
    }
    sort_three_element(deq_a);
    sort_two_elemen(deq_a);
    //deq이 빌 때까지 while문을 돌리는 것이 맞는지
    pa (deq_a, deq_b);
    pa (deq_a, deq_b);
}


void    sort(t_deq *deq_a, t_deq *deq_b)
{
    if (deq_a->a_size == 1)
        return ;
    else if (deq_a->a_size == 2 && !check_sort(deq_a))
        sort_two_element(deq_a);
    else if (deq_a->a_size == 3 && !check_sort(deq_a))
        sort_three_element(deq_a);
    else if (deq_a->a_size == 4 && !check_sort(deq_a))
        sort_four_element(deq_a);
    else if (deq_a->a_size == 5 && !check_sort(deq_a))
        sort_five_element(deq_a);
    else if (!check_sort(deq_a))
        greedy(deq_a, deq_b);
}

void greedy(t_deq *deq_a, t_deq *deq_b)
{
    int min_loc;

    pre_setting_deque(deq_a, deq_b);
    get_rot_count(deq_a, deq_b);
    if (!check_sort(deq_a))
    {
        min_loc = find_min_loc(deq_a);
        while (min_loc > 0)
        {
            ra(deq_a);
            min_loc--;
        }
        while (min_loc < 0)
        {
            rra(deq_a);
            min_loc++;
        }
    }
}


int get_max_value(t_deq* deq_a)
{
    int max;
    t_deq *temp;

    temp = deq_a;
    max = INT_MIN;

    while(temp->a_top)
    {
        if (max < temp->a_top->index)
            max = temp->a_top->index;
        temp->a_top = temp->a_top->next;
    }
    return (max);
}

int get_min_value(t_deq* deq_a)
{
    int min;
    t_deq *temp;

    temp = deq_a;
    min = INT_MAX;

    while(temp->a_top)
    {
        if (min > temp->a_top->index)
            min = temp->a_top->index;
        temp->a_top = temp->a_top->next;
    }
    return (min);
}


// ------
// sorting에서 명령어를 실행하는 부분, 꼭, 꼭 만들어야 한다.
// pa 나 pb 그런식으로요.

void get_min_rotation(int *a, int *b)
{
    int a_loc;
    int b_loc;
    t_deq *deq;
    int num;

    i = 0;
    stack_b = b_top;


    while(idx < deq->size_b)
    {
        num = deq_b->content;
        a_loc = set_a_loc(num, t_deq);
        if (idx >= (deq_b + 1) / 2)
            b_loc = (t_deq->b_size - idx) * -1;
        else 
            b_loc = idx;
        if (idx == 0 || ft_get_bigger(*a, *b, a_loc, b_loc)
        {
            *a = a_loc;
            *b = b_loc;
        }
        deq_b = deq_b->next;
        idx++;
    }
}

