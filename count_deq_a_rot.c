/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_deq_a_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:19:28 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/09 14:11:44 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*t_deq *temp;
temp = deq_a;

int deq_a_loc;
deq_a_loc = 0;

int cur_loc;
cur_loc = 0;

int flag;
flag = 0;

while (temp)
{
	if (deq_a의 인자 > deq_b의 인자 && deq_a의 인자 < 최솟값이라고 생각하는 수)
	{
		최솟값이라고 생각하는 수 = deq_a의 인자;
		deq_a_loc = cur_loc; //실제 방출되어야 할  위치
		flag = 1;
	}
	temp = temp->next;
	cur_loc++;
}
if(flag == 1)
	return(deq_a_loc);

temp = deq_a;
cur_loc = 0;
while (temp)
{
	if(deq_a의 인자 < 최솟값이라고 생각하는 수)
	{
		최솟값이라고 생각하는 수 = deq_a의 인자;
		deq_a_loc = cur_loc;
	}
	temp = temp->next;
	cur_loc++;
}
return (deq_a_loc); */



// deq_b의 요소를 잡은 다음에 시작
// deq_b에 대한 while문 안에 있는 상횡이 되는  거.
// deq_a에 대해서만 반복문 돌아가는 상황
int get_a_loc(t_deq* deq_a, int b_content) //deq_b_b_top_content)
{
	int deq_a_loc;
	int cur_loc;
	int min;
	int min_a;
	t_deq* temp;

	deq_a_loc = 0;
	cur_loc = 0;
	min = 0;
	min_a = INT_MAX;
	temp = deq_a;

	while (temp->a_top)
	{
		if (b_content > temp->a_top->content)
		{
			if (min > b_content - temp->a_top->content)
			{
				min = b_content - temp->a_top->content;
				deq_a_loc = cur_loc;
			}
		}
		temp->a_top = temp->a_top->next;
		cur_loc++;
	}
	// 같을 경우가 있겠지만 괜찮을 거 같아.
	if (min == 0)
	{
		temp = deq_a;
		cur_loc = 0;
		while(temp->a_top)
		{
			if (temp->a_top->content < min_a)
			{
				min_a = temp->a_top->content;
				deq_a_loc = cur_loc;
			}
			temp->a_top = temp->a_top->next;
			cur_loc++;
		}
	}
	return (deq_a_loc);
}















// // 나은 거 같지만 동일한 if문이 중복되서 별로
// // 나중에 리팩토링으로 다시 한 번 시도해 볼 것
// int get_a_loc(t_deq* deq_a)
// {
// 	while (temp)
// 	{
// 		if (deq_a의 인자 > deq_b의 인자)
// 		{
// 			if (deq_a의 인자 > deq_b의 인자 && deq_a의 인자 < 최소값이라고 생각하는 수)
// 			{
// 				최소값이라고 생각하는 수 = deq_a의 인자;
// 				deq_a_loc = cur_loc;
// 			}
// 		}
// 		else
// 			if (deq_a의 인자 < 최소값이라고 생각하는 수) 
			
// 			{
// 				최소값이라고 생각하는 수 = deq_a의 인자;
// 				deq_a_loc = cur_loc;
// 			}
// 			temp = temp->next;
// 			cur_loc++;
// 	}
// 	return (deq_a_loc);	
// }








/*
// ra rb -> rr
// if(idx < size /2)
// (deq_a의 사이즈 - idx) * -1;

// 양수 / 음수



/*deq a
---------
1
3
4
---------
3의 순번 
int *arr;
arr의 idx;

idx = rotation 회수
*/

// // 스택 a에서 rotation을 몇 번 해야하는지 체크하는 함수

// int rot_a_count()
// {
	


// }

