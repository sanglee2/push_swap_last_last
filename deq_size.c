/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:16:22 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:17 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// t_deq에 노드 접근할 수 있는 방식을
// a_top, b_top으로 따로 나눠놓다보니 각 노드의 접근이 힘들어.
// 힘들어져.. 함수를 일단 2개로 나누는 생각
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


int get_deq_b_size(t_deq *deq_b)
{
	t_deq* temp;
	int size;

	temp = deq_b;
	size = 0;
	while (temp->b_top)
	{
		size++;
		temp->b_top = temp->b_top->next;
	}
	return (size);
}