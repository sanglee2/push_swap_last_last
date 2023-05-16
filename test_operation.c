/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:18 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/16 18:02:50 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void push_top_b(t_deq *deq, t_node *node)
{
	if (deq->b_size == 0)
	{
		deq->b_top = node;
		deq->b_bot = node;
	}
	else if (deq->b_size == 1) // 이중 연결리스트 때문에 일어나는 일일
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
	deq->b_size++;
}


void pb(t_deq *deq_a, t_deq *deq_b)
{
	t_node *temp;

	if (deq_a->a_size < 1)
		return ;
	
	// 
	else
	{
		temp =  deq_a->a_top;

		if (deq_a->a_size == 1)
		{
			deq_a->a_top = NULL;
			deq_a->a_bot = NULL;
		}

		if (deq_a->a_size > 1)
		{
			deq_a->a_top = deq_a->a_top->next;
			deq_a->a_top->prev = NULL;
		}

		if (deq_b->b_size < 1)
		{
			temp->next = NULL;
			temp->prev = NULL;
			deq_b->b_top = temp;
			deq_b->b_bot = temp;
		} 
		push_top_b(deq_b, temp);
	}

	deq_a->a_size = deq_a->a_size + 1;
	deq_b->b_size = deq_b->b_size - 1;
	write(1, "pb\n", 3);	
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

	ra(deq_a);
	ra(deq_a);

	//pb(deq_a, deq_b);

	deq_print(deq_a);

	//sort_two_element(deq_a);
	//sort_three_element(deq_a);
	//sort_four_element(deq_a, deq_b);
	//deq_print(deq_a);
	//deq_print(deq_b);*/
}