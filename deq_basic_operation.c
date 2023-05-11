/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_basic_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:36:02 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:09 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// 굳이 이중 연결리스트로 구현을 해야 했을까?

void push_top(t_deq *deq, t_node *node)
{
	if (deq->a_size == 0)
	{
		deq->a_top = node;
		deq->a_bot = node;
	}
	else if (deq->a_size == 1) // 이중 연결리스트 때문에 일어나는 일일
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
	deq->a_size++;
}

// 각 요소의 포인터인지 배열인지 따라 인수 결정
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

t_node*	pop_top(t_deq *deq)
{
	// 왜 선언을 했을지? 필요한 부분인지
	// 해당 변수를 가리키는 포인터를 선언했다 의미.
	//t_node *node;
	t_node *temp;
	//int arg;


	// node인 deq의 a_top 부분을 계속 이동시키기.
	// 해당노드를 방출하기.
	temp = deq->a_top;

	//deq이 비어있는지 확인.
	if (is_empty(deq) == 1)
		return (NULL);

	if (deq->a_size == 1)
	{
		deq->a_top = NULL;
		deq->a_bot = NULL;
	}
	else
	{
		deq->a_top = temp->next;
		//deq->a_top = deq->a_top->next;
		deq->a_top->prev = NULL;
	}
	temp->next = NULL; // 다음 노드를 가리키던 거 NULL값으로.
	//free(temp); //왜 필요한지?
	deq->a_size--;
	return (temp);
} 

t_node* pop_bot(t_deq *deq)
{
	t_node *temp;

	temp = deq->a_bot;

	//deq이 비어있는지 확인.
	if (is_empty(deq) == 1)
		return (NULL);
	
	if (deq->a_size == 1)
	{
		deq->a_top = NULL;
		deq->a_bot = NULL;
	}

	else
	{
		deq->a_bot = temp->prev;
		deq->a_bot->next = NULL;
	}
	temp->prev = NULL;
	deq->a_size--;
	return (temp);
}





















// void push_top(t_stack *stack, t_node *node)
// {
// 	if (stack->a_size == 0)
// 	{
// 		stack->a_top = node;
// 		stack->a_bot = node;
// 	}
// 	else if (stack->a_size == 1) // 이중 연결리스트 때문에 일어나는 일일
// 	{
// 		stack->a_bot->prev = node;
// 		node->next = stack->a_top;
// 		//stack->a_top = node;
// 		//stack->a_top->next = stack->a_bot;
// 		stack->a_top = node;

// 	}
// 	else
// 	{
// 		stack->a_top->prev = node;
// 		node->next = stack->a_top;
// 		stack->a_top = node;	
// 	}
// }

// // 각 요소의 포인터인지 배열인지 따라 인수 결정
// void push_bot(t_deq *deq, t_node *node)
// {
// 	// deq a가 비어있을 때.
// 	// top 과 bot 모두가 현재 노드를 가리킬 수 있도록.
// 	if (deq->a_size == 0)
// 	{
// 		deq->a_top = node;
// 		deq->a_bot = node;
// 	}
// 	else if (deq->a_size == 1)
// 	{
// 		deq->a_top->next = node;
// 		deq->a_bot = node;
// 		deq->a_bot->prev = deq->a_top;
// 	}
// 	else
// 	{
// 		deq->a_bot->next = node;
// 		node->prev = deq->a_bot;
// 		deq->a_bot = node;
// 	}
// }


// t_node* pop_top(t_stack *stack)
// {
// 	t_node *node;

// 	//stack이 비어있는지 확인.
// 	node = stack->a_top;
// 	stack->a_top = node->next;
// 	return (node);
// } 

// t_node* pop_bot(t_stack *stack)
// {
// 	t_node *node;

// 	//stack이 비어있는지 확인.
// 	node = stack->a_bot;
// 	stack->a_bot = node->prev;
// 	return (node);
// }