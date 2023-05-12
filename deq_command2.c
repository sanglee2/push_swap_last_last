/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:33:31 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 05:40:36 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ra(t_deq *deq_a)
{
	push_bot(deq_a, deq_a->a_top); // a_top에 있던 원래의 것들을 잘 제거. 잘라야 함.
	deq_a->a_top  = deq_a->a_top->next;
	write(1, "ra\n", 3);
}

void rb(t_deq *deq_b)
{
	push_bot(deq_b, deq_b->b_top);
	deq_b->b_top = deq_b->b_top->next;
	write(1, "rb\n", 3);
}

void rr(t_deq *deq_a)
{
	ra(deq_a);
	rb(deq_b);
	write(1, "rr\n", 3);
}

void rra(t_deq *deq_a)
{
	push_top(deq_a, deq_a->a_bot);
	deq_a->a_bot = deq_a->a_bot->prev;
	write(1, "rra\n", 4);
}

void rrb(t_deq *deq_a)
{
	push_top(deq_b, deq_b->b_bot);
	deq_b->b_bot = deq_b->b_bot->prev;
	write(1, "rrb\n", 4);
}

void rrr(t_deq *deq_a)
{
	rra(deq_a);
	rrb(deq_b);
	write(1, "rrr\n", 4);
}