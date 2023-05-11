/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:15:24 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:10 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 명령어 관련 작성부분

void pa(t_stack *stack) // stack에 대한 전부가 넘어와야 되나? --> 되는가?
{
	t_node *temp;

	if (stack->b_size < 1)
		return ;

	temp = stack->b_top; // b의 제일 위를 가리키게 해야 함.

	if (stack->b_size >= 1)
	{
		stack->b_top = stack->b_top->next;
		stack->b_top->prev = NULL;
	}

	push_top(stack, temp);

	stack->a_size = stack->a_size + 1;
	stack->b_size = stack->b_size - 1;
	write(1 "pa\n", 3);
}

void pb(t_stack *stack)
{
	t_node *temp;

	if (stack->a_size < 1)
		return ;
	
	temp =  stack->a_top;

	if (stack->a_size >= 1)
	{
		stack->a_top = stack->a_top->next;
		stack->b_top->prev = NULL;
	}

	push_top(stack, temp);

	stack->a_size = stack->a_size + 1;
	stack->b_size = stack->b_size - 1;
	wirte(1, "pb\n", 3);	
}

void sa(t_stack *stack)
{
	t_node *temp;

	temp = stack->a_top->content;
	stack->a_top->content = stack->a_top->next->content;
	stack->a_top->next->content = temp;	
	wirte(1, "sa\n", 3);
}

void sb(t_stack *stack)
{
	t_node *temp;

	temp = stack->b_top->content;
	stack->b_top->content = stack->b_top->next->content;
	stack->b_top->next->content = temp;
	wirte(1, "sb\n", 3);
}

// sa와 sb를 동시에 한다?

void ss(t_stack *stack)
{
	t_node *temp;
	temp = stack->a_top->content;
	stack->a_top->content = stack->a_top->next->content;
	stack->a_top->next->content = temp;	
	temp = stack->b_top->content;
	stack->b_top->content = stack->b_top->next->content;
	stack->b_top->next->content = temp;
	write(1, "ss\n", 3);
}

void ra(t_stack *stack)
{
	t_node *temp;
	if (stack->a_size < 2)
		return;
	temp = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_top->prev = NULL;
	stack->a_bot->next = temp;
	temp->prev = stack->a_bot;
	stack->a_bot = temp;
	stack->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void rra(t_stack *stack)
{
	t_node *temp;
	temp = stack->a_bot;
	stack->a_bot = stack->a_bot->prev;
	stack->a_bot->next = NULL;
	stack->a_top->prev = temp;
	temp->next = stakc->a_top;
	stack->a_top = temp;
	stack->a_top->prev = NULL;
	write(1, "rra\n", 3);
}






























