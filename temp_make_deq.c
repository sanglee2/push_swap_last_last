/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:49:11 by sanglee2          #+#    #+#             */
/*   Updated: 2023/04/29 05:17:46 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 스택 초기화 하는 부분이 필요하다.
// atoi에서 인자를 어떻게 받아올지.

t_node* init_node(int data) // calloc + content만 data. -- calloc
							// count = 1, sizeof (구조체)
{
	t_node *node;

	node = (t_node *)malloc(1 * sizeof(t_node));
	if (!node)
		return (0);
	node->prev = NULL;
	node->content = data;
	node->next = NULL;
	return (node);
}

t_stack* make_stack(t_stack *stack, int data)
{
	t_node *node;
	node = init_node(data); //노드 초기화.
	push_bot(stack, node); // bot에 인자들 추가하기.
	return (stack);
}

//stack


















