/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hardcoding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 05:39:11 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 20:54:42 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void push_top(t_deq *deq, t_node *node)
{
	if (deq->a_size == 0)
	{
		deq->a_top = node;
		deq->a_bot = node;
	}
	else if (deq->a_size == 1) // 이중 연결리스트 때문에 일어나는 일일
	{
		deq->a_bot->prev = node;
		node->next = deq->a_top;
		//deq->a_top = node;
		//deq->a_top->next = deq->a_bot;
		deq->a_top = node;

	}
	else
	{
		deq->a_top->prev = node;
		node->next = deq->a_top;
		deq->a_top = node;	
	}
	deq->a_size++;
}

void push_bot(t_deq *deq, t_node *node)
{
	// deq a가 비어있을 때.
	// top 과 bot 모두가 현재 노드를 가리킬 수 있도록.
	if (deq->a_size == 0)
	{
		deq->a_top = node;
		deq->a_bot = node;
	}
	else if (deq->a_size == 1)
	{
		deq->a_top->next = node;
		deq->a_bot = node;
		deq->a_bot->prev = deq->a_top;
	}
	else
	{
		deq->a_bot->next = node;
		node->prev = deq->a_bot;
		deq->a_bot = node;
	}
	deq->a_size++;
}

void pa(t_deq *deq_a, t_deq *deq_b) // stack에 대한 전부가 넘어와야 되나? --> 되는가?
{
	t_node *temp;

	if (deq_b->b_size < 1)
		return ;

	temp = deq_b->b_top; // b의 제일 위를 가리키게 해야 함.

	if (deq_b->b_size >= 1)
	{
		deq_b->b_top = deq_b->b_top->next;
		deq_b->b_top->prev = NULL;
	}

	push_top(deq_b, temp);

	deq_a->a_size = deq_a->a_size + 1;
	deq_b->b_size = deq_b->b_size - 1;
	write(1, "pa\n", 3);
}

void pb(t_deq *deq_a, t_deq *deq_b)
{
	t_node *temp;

	if (deq_a->a_size < 1)
		return ;
	
	temp =  deq_a->a_top;

	if (deq_a->a_size >= 1)
	{
		deq_a->a_top = deq_a->a_top->next;
		deq_a->b_top->prev = NULL;
	}

	push_top(deq_a, temp);

	deq_a->a_size = deq_a->a_size + 1;
	deq_b->b_size = deq_b->b_size - 1;
	write(1, "pb\n", 3);	
}



void sa(t_deq *deq_a)
{
	int temp;

	temp = deq_a->a_top->content;
	deq_a->a_top->content = deq_a->a_top->next->content;
	deq_a->a_top->next->content = temp;	
	//wirte(1, "sa\n", 3);
}

// void ra(t_deq *deq_a)
// {
// 	push_bot(deq_a, deq_a->a_top); // a_top에 있던 원래의 것들을 잘 제거. 잘라야 함.
// 	deq_a->a_top  = deq_a->a_top->next;
// 	write(1, "ra\n", 3);
// }

// void rra(t_deq *deq_a)
// {
// 	push_top(deq_a, deq_a->a_bot);
// 	deq_a->a_bot = deq_a->a_bot->prev;
// 	write(1, "rra\n", 4);
// }


void ra(t_deq *deq_a)
{
	t_node *temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_top;
	deq_a->a_top = deq_a->a_top->next;
	deq_a->a_top->prev = NULL;
	deq_a->a_bot->next = temp;
	temp->prev = deq_a->a_bot;
	deq_a->a_bot = temp;
	deq_a->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void rra(t_deq *deq_a)
{
	t_node *temp;
	temp = deq_a->a_bot;
	deq_a->a_bot = deq_a->a_bot->prev;
	deq_a->a_bot->next = NULL;
	deq_a->a_top->prev = temp;
	temp->next = deq_a->a_top;
	deq_a->a_top = temp;
	deq_a->a_top->prev = NULL;
	write(1, "rra\n", 3);
}

void sort_two_element(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;
    if (temp->content > temp->next->content)
        sa(deq_a);
    return ;
}

// hard 코딩을 테스트 해주기 위해선, 기본적인 content를 활용.
// content를 index로 바꿀 것
void sort_three_element(t_deq* deq_a)
{
    t_node *temp;
    int first;
    int second;
    int third;


    temp = deq_a->a_top;
	first = temp->content;
	second = temp->next->content;
	third = temp->next->next->content;

    if (first > second && third > first)
        sa(deq_a);
    else if (first > second && second > third)
    {
        sa(deq_a);
        rra(deq_a);
    }
    else if (second < third && third < first)
        ra(deq_a);
    else if (second > third && third > first)
    {
        sa(deq_a);
        ra(deq_a);
    }
    // 2 3 1
    else if (first < second && third < first)
        rra(deq_a);
}

int get_max_value(t_deq *deq)
{
	t_deq *temp;
	int max;

	temp = deq;
	max = INT_MIN;
	while (temp->a_top)
	{
		if (max > temp->a_top->content)
			max = temp->a_top->content;
		temp->a_top = temp->a_top->next;
	}
	return (max);
}

int get_min_value(t_deq *deq)
{
	t_deq *temp;
	int min;

	temp = deq;
	min = INT_MAX;
	while (temp->a_top)
	{
		if (min < temp->a_top->content)
			min = temp->a_top->content;
		temp->a_top = temp->a_top->next;
	}
	return (min);
}

void sort_four_element(t_deq* deq_a, t_deq* deq_b)
{
    t_deq *temp;
    int max;
    int min;

    temp = deq_a;
    max = get_max_value(deq_a);
    min = get_min_value(deq_a);

    while (temp->a_top->content)
    {
        if (temp->a_top->content == min)
            pb(deq_a, deq_b);
        else
            ra(deq_a);
        temp->a_top = temp->a_top->next;    
    }
    sort_three_element(deq_a);
    pa (deq_a, deq_b);
}


t_deq* create()
{
	t_deq *deq;
	deq = (t_deq *)malloc(sizeof(t_deq) * 1);

	return(deq);
}

void init_deq(t_deq *deq)
{
	deq->a_top = 0;
	deq->a_bot = 0;
	deq->a_size = 0;
	deq->b_top = 0;
	deq->b_bot = 0;
	deq->b_size = 0;
	deq->arr = 0;
}

int is_empty(t_deq* deq)
{
	return (deq->a_top == 0);
}

t_node* init_node(int arg)
{
	t_node *node;
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!node)
		return(0);
	
	node->prev = NULL;
	node->content = arg;
	node->next = NULL;
	return (node);	
}

void deq_print(t_deq* deq)
{
	t_node	*curr;

	curr = deq->a_top;
	while (curr)
	{
		printf("a_top data : %d\n", curr->content);
		curr = curr->next;
	}

	/*curr = deq->a_bot;
	while (curr)
	
		printf("a_bot data : %d\n", curr->content);
		curr = curr->prev;
	}*/
	curr = deq->b_top;
	while (curr)
	{
		printf("b_top data : %d\n", curr->content);
		curr = curr->next;
	}
	/*int i;
	i = 0;
	while (i < deq->arr_size)
	{
		printf("arr[%d] = %d\n", i, deq->arr[i]);
		i++;
	}*/
}

// 자주쓰는, 계속 공통적으로 들어가는 로직이면, 함수로 만들어놓자

int main()
{
	// deq을 일단 실체화해야 한다
	t_deq* deq_a;
	t_deq* deq_b;

	// node를 만들어서 구워줘야 한다.
	t_node* node1;
	t_node* node2;
	t_node* node3;
	t_node* node4;


	int arg1;
	int arg2;
	int arg3;
	int arg4;

	deq_a = create();
	//deq_b = NULL;
	deq_b = create();
	arg1 = 2;
	arg2 = 1;
	arg3 = 0;
	arg4 = 3;
	//deq을 초기화 시켜줘야 뭘 넣을 수 있다.
	init_deq(deq_a);
	init_deq(deq_b);
	node1 = init_node(arg1);
	node2 = init_node(arg2);
	node3 = init_node(arg3);
	node4 = init_node(arg4);
	push_bot(deq_a, node1);
	push_bot(deq_a, node2);
	push_bot(deq_a, node3);
	push_bot(deq_a, node4);
	deq_print(deq_a);
	deq_print(deq_b);

	//sort_two_element(deq_a);
	//sort_three_element(deq_a);
	//sort_four_element(deq_a, deq_b);
	//deq_print(deq_a);
	//deq_print(deq_b);*/
}