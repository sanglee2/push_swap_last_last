/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:16:46 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/05 21:29:01 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// 매크로 define 연습

// greedy 알고리즘 테스트

#include <stdio.h>
#include "push_swap.h"

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

int is_empty(t_deq* deq)
{
	return (deq->a_top == 0);
}

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


void deq_print(t_deq* deq)
{
	t_node	*curr;

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

int	ft_atoi(const char *nptr)
{
	size_t			i;
	int				sign;
	long long int	num_integer;

	i = 0;
	sign = 1;
	num_integer = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' )
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num_integer = num_integer * 10 + nptr[i] - '0';
		i++;
	}
	num_integer = num_integer * sign;
	return (num_integer);
}

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
		//arg = av[i];
		node = init_node(arg); // 이름이 똑같은 node가 문제? 포인터인 node가 문제?
		push_bot(deq_a, node); // 노드라는게 계속 다른게 할당 되어야 할 텐데..
		i++;
	}
	return (deq_a);
}


//int main(int ac, char* av[])
int main()
{
	t_deq* deq_a;
	t_node* node1;
	t_node* node2;
	t_node* node3;
	t_node* node4;

	int arg1;
	int arg2;
	int arg3;
	int arg4;


	deq_a = create();
	arg1 = 1;
	arg2 = 2;
	arg3 = 3;
	arg4 = 4;
	init_deq(deq_a);
	node1 = init_node(arg1);
	node2 = init_node(arg2);
	node3 = init_node(arg3);
	node4 = init_node(arg4);
	push_bot(deq_a, node1);
	push_bot(deq_a, node2);
	push_bot(deq_a, node3);
	push_bot(deq_a, node4);
	pop_top(deq_a);
	pop_bot(deq_a);

	// deq_a = configuration_deq(ac, av);
	deq_print(deq_a);
}










/*int main()
{
	int n;
	int count;
	int coinTypes[4];

	n = 0;
	count = 0; 
	coinTypes[4] = 


}*/
