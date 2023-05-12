/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:42:13 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 05:38:04 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void act_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot)
{	
	if (a_rot < 0)
		iterate_rra(deq_a, a_rot);
	iterate_ra(deq_a, a_rot);
	if (b_rot < 0)
		iterate_rra(deq_b, b_rot);
	iterate_rb(deq_b, b_rot);
	pa(deq_a, deq_b);
}

// deq_b에서
// b에 대한 순회를 잘 돌릴 예정
// get_b_loc을 그냥 b_loc 변수, while문 반복마다 증감시켜서
// b_loc 값 update해줘도 상관 없었을 듯..
void get_rot_count(t_deq* deq_a, t_deq* deq_b)
{
	t_deq *temp;
	int a_loc;
	int b_loc;
	int a_rot;
	int b_rot;
	int min;

	temp = deq_b;
	a_loc = 0;
	b_loc = 0;
	min = INT_MAX;

	while (temp->b_top)
	{	
		b_loc = get_b_loc(deq_b, temp->b_top->content);
		a_loc = get_a_loc(deq_a, temp->b_top->content);
		if (min > ft_abs(a_loc) + ft_abs(b_loc))
		{
			min = ft_abs(a_loc) + ft_abs(b_loc);
			a_rot = a_loc;
			b_rot = b_loc;
		}
		temp->b_top = temp->b_top->next;
	}
	act_sort(deq_a, deq_b, a_rot, b_rot);
}

// //rotation 횟수를 얻어내는 함수가 먼저 선행되어야 함. 실행되어야
// //rotation 횟수를 받는다.
// //rotate 명령어 사용해, deq_a, deq_b를 원하는 순서로 정렬한 후
// //pa 명령어를 통해 끝내준다.
// //++ a_idx : deq_a와 deq_b에 모두 연관되어 구해진 값이다.
// //++ a_idx를 조금 더 깔끔하게 표현해 줄 수 있는 방법은 없을까? - 좀 더 와닿는 변수명.
// void perform_sort(t_deq* deq_a, t_deq* deq_b,a_idx,b_idx)
// {
// 	if (a_idx > a_size / 2)
// 	{
// 		a_idx = a_size - a_idx;
// 		rra(a,가공된 a_idx);
// 	}
// 	ra(a,a_idx);
// 	if (b_idx > b_size / 2)
// 	{
// 		b_idx = b_size - b_idx;
// 		rrb(b,가공된 b_idx);
// 	}
// 	rb(b,b_idx);
// 	pa(a, b);
// }

// // 필요없는 껍데기 함수가 되어버림.
// // 필요업어지게 된 인자
// void prepare_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot)
// {
// 	t_deq *temp_a;
// 	t_deq *temp_b;
// }





// //어떤게 
// int get_min_rot_arg(t_deq *deq_a, t_deq *deq_b)
// {


// }


// // while문 안에서 돌거니까 상관없어
// // 한 b요소당 a,b의 각 rotation 횟수 구하는 함수.
// int get_rot_count(t_deq *deq_a, int b_content)
// {
// 	int count_a;
// 	int count_b;


// 	count_a = get_a_loc(deq_a, b_content);

// 	count_b = get_b_loc(deq_b);
// 	return (count_a + count_b);
// }


// act_sort의 기록! 기록들!

// void act_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot)
// {	
// 	if (a_rot > deq_a->a_size / 2)
// 	{
// 		a_rot = deq_a->a_size - a_rot;
// 		iterate_rra(deq_a, a_rot);
// 	}
// 	iterate_ra(deq_a, a_rot);
// 	if (b_rot > b_size / 2)
// 	{
// 		b_rot = b_size - b_rot;
// 		iterate_rra(deq_b, b_rot);
// 	}
// 	iterate_rb(deq_b, b_rot);
// 	pa(deq_a, deq_b);
// }