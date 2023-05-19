/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:01:32 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/19 18:39:28 by sanglee2         ###   ########.fr       */
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



int ft_abs(int num)
{	
	if (num < 0)
		num = num * -1;
	return (num);
}


int get_a_loc(t_deq* deq_a, int b_content) //deq_b_b_top_content)
{
	int deq_a_loc;
	int cur_loc;
	int min;
	int min_a;
	t_deq* temp;

	deq_a_loc = 0;
	cur_loc = 0;
	min = INT_MAX;
	min_a = INT_MAX;
	temp = deq_a;

	while (temp->a_top)
	{
		if (b_content < temp->a_top->content)
		{
			if (min > temp->a_top->content - b_content)
			{
				min = temp->a_top->content - b_content;
				deq_a_loc = cur_loc;
			}
		}
		temp->a_top = temp->a_top->next;
		cur_loc++;
	}
	// 같을 경우가 있겠지만 괜찮을 거 같아.
	if (min == INT_MAX)
	{
		temp = deq_a;
		cur_loc = 0;
		while(temp->a_top)
		{
			if (temp->a_top->content < min_a)
			{
				min_a = temp->a_top->content;
				deq_a_loc = cur_loc;
			}
			temp->a_top = temp->a_top->next;
			cur_loc++;
		}
	}
	if (deq_a_loc > temp->a_size / 2)
		deq_a_loc = (temp->a_size - deq_a_loc) * -1;
	return (deq_a_loc);
}

int get_b_loc(t_deq *deq_b, int b_content)
{
	t_deq *temp;
	int cur_loc;
	int b_loc;
	
	temp = deq_b;
	cur_loc = 0;
	b_loc = 0;

	while (temp->b_top)
	{
		if (b_content == temp->b_top->content)
			b_loc = cur_loc;
		temp->b_top = temp->b_top->next;
		cur_loc++;
	}

	if (b_loc > temp->b_size / 2)
		b_loc = (temp->b_size - b_loc) * -1; 
	return (b_loc);
}

void act_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot)
{	
	if (a_rot < 0)
		iterate_rra(deq_a, a_rot);
	iterate_ra(deq_a, a_rot);
	if (b_rot < 0)
		iterate_rra(deq_b, b_rot);
	iterate_rb(deq_b, b_rot);
	pa(deq_a, deq_b);
}

void get_rot_count(t_deq* deq_a, t_deq* deq_b)
{
	t_node *temp;
	int a_loc;
	int b_loc;
	int a_rot;
	int b_rot;
	int min;

	temp = deq_b->b_top;
	a_loc = 0;
	b_loc = 0;
	min = INT_MAX;

	while (temp)
	{	
		b_loc = get_b_loc(deq_b, temp->content);
		a_loc = get_a_loc(deq_a, temp->content);
		if (min > ft_abs(a_loc) + ft_abs(b_loc))
		{
			min = ft_abs(a_loc) + ft_abs(b_loc);
			a_rot = a_loc;
			b_rot = b_loc;
		}
		temp = temp->next;
	}
	act_sort(deq_a, deq_b, a_rot, b_rot);
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
		get_rot_count(deq_a, deq_b);
        //greedy(deq_a, deq_b);
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


	get_rot_count(deq_a, deq_b);

	deq_print(deq_a);
	//deq_print(deq_b);

	//if(!check_sort(deq_a))
		//last_setting_deque(deq_a);

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
