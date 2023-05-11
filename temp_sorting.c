/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:47:53 by sanglee2          #+#    #+#             */
/*   Updated: 2023/04/28 18:49:48 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// deq b에서 인자 하나 잡고, deq a의 모든 인자 비교해서
// 

















// deq_b의 인자마다 모든 명령어 개수 파악하기.

int find_min_act_arg()
{
	min = count_a_rot() + count_b_rot();
}

// a와 b의 비교
t_deq *temp;
temp = deq_a;

while (temp)
{
	if (덱 a의 인자 > 덱 b의 인자 && 덱 a의 인자 < 제일 작은 놈의 값)
	{
		제일 작은 놈의 값 = 덱 a의 인자;
	}
	temp = temp->next;
}

while ()
{
	if (덱 a의 인자의 위치 < 제일 작은 놈의 값)
	{
		제일 작은 놈의 값 = 덱 a 인자의 위치;
	}
	temp = temp->next;
}

// a와 b 비교









// deq_b의 각 요소에 대해 맞는 위치의 deq_a의 loc 찾는 함수 -> 집어넣어야 할 곳 -> deq_a의 loc 위치 ->  rotation을 해 줄 횟수
void find_loc(t_deq **deq_a, t_deq **deq_b)
{
	t_node *temp;	// t_node *temp로 찾는데 어려웠던 부분.
	temp = *deq_a->a_top;

	t_deq *tmp;
	tmp = *deq_a;

	while(tmp->a_top)
	{
		if(*deq_b->)
		tmp->a_top = tmp->a_top->next;
	}

	while(temp)
	{
		if(temp->content>temp_b->content && )
		temp = temp->next;
	}
	temp = deq_a->a_top;
	while (temp)
	{



	}
}





// 이 함수 고쳐봤으면 하는 거 
int count_a_rot(t_deq **deq_a, t_deq **deq_b)
{
	t_deq *temp;
	int idx;
	int min;
	int store;


	temp = *deq_b;
	idx = 0;
	min = 0;
	store = 0;

	while(temp)
	{
		find_loc();
		temp = temp->next;
	}



}
























// 이 함수를 조금 더 고쳐봤으면 하는 거
int count_a_rot(deq_a)
{
	int store;
	int idx;
	int min;

	idx = 0;
	store = 0;
	min = 0;

	//idx = get_deq_size(deq_a)

	while (idx < size)
	{

		if (min > b - a && b < a)
		{
			min = b - a;
			store = idx;
		}
		idx++;
	}
	idx = 0;
	while (idx < size)
	{
		// 스택 내에서 가장 작은 인수 찾기. - 함수 호출
	}
	return(idx);
}


















// 스택 b에서 가장 큰 값


// 스택 a에서 가장 큰 값
int count_b_rot()






// 
while (i < size)
{	



}

while


while()
{
	
}

// 최대값 출력



// a의 개수 구하는 함수 작성.
int count_a_rot(deq_a)
{
	int store;
	int idx;
	int min;

	idx = 0;
	store = 0;
	min = 0;

	//idx = get_deq_size(deq_a)

	while (idx < size)
	{

		if (min > b - a && b < a)
		{
			min = b - a;
			store = idx;
		}
		idx++;
	}
	idx = 0;
	while (idx < size)
	{
		// 스택 내에서 가장 작은 인수 찾기. - 함수 호출
	}
	return(idx);
}

// b개수 구하는 함수 작성
int count_b_rot(deq_b)
{
	while(idx < size)
	{
		
	}
}

while (/* condition */)
{
	/* code */
}


int find_min_idx(t_deq *deq)
{
	int min;
	int i;

	i = 0;
	while (i < deq->size)
	{
		if (min > deq->arr[i])
			min = deq->arr[i]
		i++;

	}

	i = 0;
	while (i < deq->size)
	{
		if (min == deq->arr[i])
			return (i);
		i++;
	}
}














// 실제 실행하는 함수

do_move()
{
	
}



int main()
{
	printf("char: %d", sizeof(void *))
}


void	sorting(t_deq **deq_a, t_deq **deq_b)
{
	while(*deq_b)
	{
		
	}



}


