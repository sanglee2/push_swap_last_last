/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_partial_greedy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:40:35 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/19 21:10:29 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

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

int get_deq_a_size(t_deq *deq_a)
{
	t_deq* temp;
	int size;

	temp = deq_a;
	size = 0;
	while (temp->a_top)
	{
		size++;
		temp->a_top = temp->a_top->next;
	}
	return (size);
}


int get_a_loc(t_deq* deq_a, int b_content) //deq_b_b_top_content)
{
	int deq_a_loc;
	int cur_loc;
	int min;
	int min_a;
	t_node* temp;

	deq_a_loc = 0;
	cur_loc = 0;
	min = INT_MAX;
	min_a = INT_MAX;
	temp = deq_a->a_top;

	while (temp)
	{
		if (b_content < temp->content)
		{
			if (min > temp->content - b_content)
			{
				min = temp->content - b_content;
				deq_a_loc = cur_loc;
			}
		}
		temp = temp->next;
		cur_loc++;
	}
	printf("가장 작은 차이값 min 값은 : %d\n", min);
	// 같을 경우가 있겠지만 괜찮을 거 같아.
	if (min == INT_MAX)
	{
		temp = deq_a->a_top;
		cur_loc = 0;
		while(temp)
		{
			if (temp->content < min_a)
			{
				min_a = temp->content;
				deq_a_loc = cur_loc;
			}
			temp = temp->next;
			cur_loc++;
		}
		printf("가장 작은 min_a 값은 : %d\n", min_a);
	}
	// 없어져야 할 부분
	deq_a->a_size = get_deq_a_size(deq_a);
	if (deq_a_loc > deq_a->a_size / 2)
		deq_a_loc = (deq_a->a_size - deq_a_loc) * -1;
	printf("ra횟수는 : %d", deq_a_loc);
	return (deq_a_loc);
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

	// temp처럼 deq->a_top으로 두는 둔 이유
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





int main()
{
	// deq을 일단 실체화해야 한다
	t_deq* deq_a;


	// node를 만들어서 구워줘야 한다.
	t_node* node1;
	t_node* node2;
	t_node* node3;
	t_node* node4;
	t_node* node5;


	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	int b_content;


	deq_a = create();
	//deq_b = NULL;
	//deq_b = create();
	arg1 = 5;
	arg2 = 6;
	arg3 = 7;
	arg4 = 1;
	arg5 = 3;
	b_content = 100;

	//deq을 초기화 시켜줘야 뭘 넣을 수 있다.
	init_deq(deq_a);
	//init_deq(deq_b);
	node1 = init_node(arg1);
	node2 = init_node(arg2);
	node3 = init_node(arg3);
	node4 = init_node(arg4);
	node5 = init_node(arg5);

	push_bot(deq_a, node1);
	push_bot(deq_a, node2);
	push_bot(deq_a, node3);
	push_bot(deq_a, node4);
	push_bot(deq_a, node5);



	deq_print(deq_a);
	//deq_print(deq_b);

	//if(!check_sort(deq_a))
		//last_setting_deque(deq_a);

	get_a_loc(deq_a, b_content);

	//get_rot_count(deq_a, deq_b);
	//sort_two_element(deq_a);
	//sort_three_element(deq_a);
	//sort_four_element(deq_a, deq_b);
	//sort_five_element(deq_a, deq_b);
	//last_setting_deque(deq_a, deq_b);
	deq_print(deq_a);
	//deq_print(deq_b);
	//deq_print(deq_a);
	//deq_print(deq_b);*/
}
