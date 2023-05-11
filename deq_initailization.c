/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_initailization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 08:18:15 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:14 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // 스택 초기화 하는 부분이 필요하다.
// // atoi에서 인자를 어떻게 받아올지.

// t_node* init_node(int data) // calloc + content만 data. -- calloc
// 							// count = 1, sizeof (구조체)
// {
// 	t_node *node;

// 	node = (t_node *)malloc(1 * sizeof(t_node));
// 	if (!node)
// 		return (0);
// 	node->prev = NULL;
// 	node->content = data;
// 	node->next = NULL;
// 	return (node);
// }
// //stack

// // deq_a, deq_b 필요한 만큼, 필요한 형식으로 초기화.

// t_deq *deq_init(t_deq *deq_a)
// {
// 	push_bot(deq_a, node); //node에 담았던 데이터들이 필요한 부분 아니냐?
// 	deq_a->a_size = 
// }


// /*
// // 함수 내에서 호출할 함수의 매개변수를 확인하기 위해 작성함.
// void push_bot(t_deq *deq, t_node *node)
// */


// //int a;
// //char a;
// //int a[5];
// //t_struct a;

// //malloc으로 변수할당
// /*
// 	int *a;
// 	a = (int *)malloc(sizeof(int) * 1);

// 	char *a;
// 	a = (char *)malloc(sizeof(char) * 1);
// */


t_deq* create()
{
	t_deq *deq;
	deq = (t_deq *)malloc(sizeof(t_deq) * 1);

	return(deq);
}

//create 함수 실행 되었다는 전제하에
//호출위치는 그 다음.
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

// 노드를 만들고, 초기화 해주는 함수.
// deq 만들고, 초기화 하는 함수 처럼 쪼개기.
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


int is_empty(t_deq* deq)
{
	return (deq->a_top == NULL);
}



// deq을 실체화 해주는 함수
// deq에 파싱이 끝난 인자 값들을 넣어주는 함수
// 위에서 아래로 오름차순으로 넣어준다
// ex) 1 2 3 4 5 

t_deq *configuration_deq(int ac, char *av[])
{
	t_deq* deq_a;
	t_node* node;
	int arg;
	int i;

	i = 1;
	deq_a = create();
	init_deq(deq_a);

	// 노드가 계속 바뀌면서 생성이 되고 
	// 새로운 노드들이 deq에 차곡차곡 쌓이는지 확인해주는 함수
	while(i < ac)
	{
		// 문자열을 인수로 쪼개주고, 문자->정수로 바꿔서 인수화 해주는 암튼 -- ft_atoi
		// 우리가 libft에서 썼던 원 atoi함수 기능적인 부분 헤지지 않게
		arg = ft_atoi(av[i]);
		node = init_node(arg); // 이름이 똑같은 node가 문제? 포인터인 node가 문제?
		push_bot(deq_a, node); // 노드라는게 계속 다른게 할당 되어야 할 텐데..
		i++;
	}
	return (deq_a);
}



// t_deq *configuration_deq(int ac, char *av[])
// {
// 	t_deq *deq_a;
// 	long int nb;
// 	int i;

// 	//deq_a = NULL;
// 	nb = 0;
// 	i = 1;

// 	deq_a = create();
// 	init_deq(deq_a);

	


// 	while(i < ac)
// 	{
// 		nb = ft_atoi(av[i]);
// 		if (i == 1)
// 			deq_a = deq_a 첫 노드 만들어주는 함수(nb); //lstnew 참고
// 		else
// 			push_bot(deq_a, deq_a 첫 노드 만들어주는 함수(nb));
// 		i++;	
// 	}
// 	return (deq_a);
// }




