/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:15:24 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/12 11:19:05 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 명령어 관련 작성부분

void pa(t_deq *deq_b) // stack에 대한 전부가 넘어와야 되나? --> 되는가?
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
	write(1 "pa\n", 3);
}

void pb(t_deq *deq_a)
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
	wirte(1, "pb\n", 3);	
}

void sa(t_deq *deq_a)
{
	t_node *temp;

	temp = deq_a->a_top->content;
	deq_a->a_top->content = deq_a->a_top->next->content;
	deq_a->a_top->next->content = temp;	
	wirte(1, "sa\n", 3);
}

void sb(t_deq *deq_b)
{
	t_node *temp;

	temp = deq_b->b_top->content;
	deq_b->b_top->content = deq_b->b_top->next->content;
	deq_b->b_top->next->content = temp;
	wirte(1, "sb\n", 3);
}

// sa와 sb를 동시에 한다?

void ss(t_deq *deq_a)
{
	t_node *temp;
	temp = deq_a->a_top->content;
	deq_a->a_top->content = deq_a->a_top->next->content;
	deq_a->a_top->next->content = temp;	
	temp = deq_b->b_top->content;
	deq_b->b_top->content = deq_b->b_top->next->content;
	deq_b->b_top->next->content = temp;
	write(1, "ss\n", 3);
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






























