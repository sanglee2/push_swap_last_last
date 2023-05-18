/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_last_setting_deq.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:37:55 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/18 22:09:44 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

// 제일 최신 버전 함수 -- 참고.

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
	write(1, "rra\n", 4);
}

void ra(t_deq *deq_a)
{
	t_node *temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_top;
	deq_a->a_top = temp->next;
	//temp->prev = NULL;
	deq_a->a_bot->next = temp;
	temp->prev = deq_a->a_bot;
	deq_a->a_bot = temp;
	deq_a->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void iterate_rra(t_deq* deq_a, int a_loc)
{
	while (a_loc < 0)
	{
		rra(deq_a);
		a_loc++;
	}

}

void iterate_ra(t_deq* deq_a, int a_loc)
{
	while(a_loc > 0)
	{
		ra(deq_a);
		a_loc--;
	}

}

int find_min_loc(t_deq* deq)
{
	t_node* temp;
	int min_a;
	int min_loc;
	int cur_loc;

	temp = deq->a_top;
	min_a = INT_MAX;
	cur_loc = 0;

	// 순회를 할 수 있는 방법에는 여러가지가 있다.
	// deq에 연관되어있는 array가 멤버로 담겨져 있고
	// deq의 크기(size)값이 따로 저장이 되어있으면 가능하다.
	// deq의 노드를 통한 순회
	while (temp)
	{
		if (temp->content < min_a)
		{
			min_a = temp->content;
			min_loc = cur_loc;
		}
		temp = temp->next;
		cur_loc++;
	}
	if (min_loc > deq->a_size / 2)
		min_loc = (deq->a_size - min_loc) * -1;
	return (min_loc);
}

// int get_deq_a_size(t_deq *deq_a)
// {
// 	t_deq* temp;
// 	int size;

// 	temp = deq_a;
// 	size = 0;
// 	while (temp->a_top)
// 	{
// 		size++;
// 		temp->a_top = temp->a_top->next;
// 	}
// 	return (size);
// }


// cicurlar하게 정렬을 되어있으니까
// 꼬리를 문 순열을
// 가장 작은 값만 top에 오게끔 만들어주면
// 1 2 3 4 
// deque 위 부터 오름차순 정렬이 완성된다.
void last_setting_deque(t_deq* deq_a)
{
	//int deq_size;
	int min_loc;

	//deq_size = get_deq_a_size(deq_a);
	min_loc = find_min_loc(deq_a);

	if (min_loc > deq_a->a_size / 2)
	{
		min_loc = deq_a->a_size - min_loc;
		iterate_rra(deq_a, min_loc);
	}
	iterate_ra(deq_a, min_loc);
}

t_deq* create()
{
	t_deq *deq;
	deq = (t_deq *)malloc(sizeof(t_deq) * 1);

	return(deq);
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

int check_sort(t_deq *deq)
{
	t_node *temp;

	temp = deq->a_top;

	while(temp)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}


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
	t_node* node5;
	t_node* node6;
	t_node* node7;
	t_node* node8;


	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	int arg6;
	int arg7;
	int arg8;

	deq_a = create();
	//deq_b = NULL;
	//deq_b = create();
	arg1 = 5;
	arg2 = 6;
	arg3 = 7;
	arg4 = 0;
	arg5 = 1;
	arg6 = 2;
	arg7 = 3;
	arg8 = 4;
	//deq을 초기화 시켜줘야 뭘 넣을 수 있다.
	init_deq(deq_a);
	//init_deq(deq_b);
	node1 = init_node(arg1);
	node2 = init_node(arg2);
	node3 = init_node(arg3);
	node4 = init_node(arg4);
	node5 = init_node(arg5);
	node6 = init_node(arg6);
	node7 = init_node(arg7);
	node8 = init_node(arg8);
	push_bot(deq_a, node1);
	push_bot(deq_a, node2);
	push_bot(deq_a, node3);
	push_bot(deq_a, node4);
	push_bot(deq_a, node5);
	push_bot(deq_a, node6);
	push_bot(deq_a, node7);
	push_bot(deq_a, node8);
	deq_print(deq_a);
	//deq_print(deq_b);

	if(!check_sort(deq_a))
		last_setting_deque(deq_a);

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