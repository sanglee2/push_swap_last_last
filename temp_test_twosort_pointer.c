/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_twosort_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:42:42 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/08 11:51:00 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 포인터로 접근이 어려운 점.
// 어떻게 다양한 방법으로 표현할 수 있는지 여러가지 테스트

// 원형0.
void sort_two_element(t_deq *deq_a)
{
    int *lst;

    lst = deq_a->content;
    if (lst > (lst + 1))
        sa(deq_a);
    return ;
}



// 포인터로 접근이 지금 어려운 점
// 원형1.
void sort_two_element(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;
    if (temp->content > temp->next->content)
        sa(deq_a);
    return ;
}

// 원형2.

void sort_two_element(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;
    if (temp->content > (temp+1)->content)
        sa(deq_a);
    return ;
}

void sort_two_element(t_deq *deq_a)
{
	int *lst;

	lst = deq_a->a_top->content;
	//가리키는 data_type이 int라 4크기씩 증가해, 커버가 불가능하지 않을까?
	if (lst > (lst + 1))
		sa(deq_a);
	return ;

}

////////////////////////////////////////////


//원형0.
void sort_three_element(t_deq *deq_a)
{
    int *lst;

    lst = deq_a->content;
    if (lst > (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) < lst)
        sa(deq_a);
    else if (lst < (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) > lst)
    {
        sa(deq_a);
        rra(deq_a);
    }
    else if (lst > (lst + 1) && (lst + 1) < (lst + 2) && (lst + 2) > lst)
        ra(deq_a);
    else if (lst < (lst + 1) && (lst + 1) > (lst + 2) && (lst + 2) < lst)
    {
        sa(deq_a);
        ra(deq_a);
    }
    else if (lst < (lst + 1) && (lst + 1) > (lst + 2) && (lst + 2) > lst)
        rra(deq_a);
}


// circualr 순회이기 때문에, 각 요소 간 대소비교가 전부 필요함
// 3개의 대소비교.
// 3 1 2 (경우 1) (도치) 2 1 3
// 1 2 3 (경우 2) (도치) 3 2 1
// 2 1 3 (경우 3) (도치) 3 1 2
// 2 3 1 (경우 4) (도치) 1 3 2
// 1 3 2 (경우 5) (도치) 2 3 1
void sort_three_element(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;

    // 2 1 3
    if (temp->content > temp->next->content && 
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





