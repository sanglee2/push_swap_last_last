/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:33:31 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:11 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ra(t_stack *stack)
{
	push_bot(stack, stack->a_top); // a_top에 있던 원래의 것들을 잘 제거. 잘라야 함.
	stack->a_top  = stack->a_top->next;
	write(1, "ra\n", 3);
}

void rb(t_stack *stack)
{
	push_bot(stack, stack->b_top);
	stack->b_top = stack->b_top->next;
	write(1, "rb\n", 3);
}

void rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	write(1, "rr\n", 3);
}

void rra(t_stack *stack)
{
	push_top(stack, stack->a_bot);
	stack->a_bot = stack->a_bot->prev;
	write(1, "rra\n", 4);
}

void rrb(t_stack *stack)
{
	push_top(stack, stack->b_bot);
	stack->b_bot = stack->b_bot->prev;
	write(1, "rrb\n", 4);
}

void rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	write(1, "rrr\n", 4);
}