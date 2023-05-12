/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:50:51 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 05:40:30 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
{
	int i;
	int pivot;

	i = 0;
	pivot = deq_a->a_size / 2;

	while (deq_a->a_size > 5)
	{
		pb(deq_a, deq_b);
		if (deq_a->a_top->index <= pivot)
			rb(deq_a, deq_b);
		deq_a->a_size--;
	}
	sort_five_element(deq_a);
}


void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
{
	int count;
	int i;

	count = 0;
	i = 0;

	while (deq_a->a_size > 5 && i < deq_a->a_size && count < deq_a->a_size / 2)
	{
		if (deq_a->a_top->index <= deq_a->a_size / 2)
		{
			pb(deq_a, deq_b);
			count++;
		}
		ra(deq_a, deq_b);
		i++;
	}
}



void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
{
	int deq_size;
	int count;
	int i;

	deq_size = get_deq_a_size(deq_a);
	count = 0;
	i = 0;
	// 하나하나 순회 돌면서 pivot보다 작을 경우 넘길지 말지 결정

	// deque 크기가 6이하이면
	// 3개가 될 때 까지 인수들 모두 
	// deq_b에 옮겨주면 될 일이니까

	// next로 옮겨진 경우를 생각해야 하나?
	// a_top->next로 옮겨지는 게 힘듦. 힘들다.
	while (deq_size > 5 && i < deq_size && count < deq_size / 2)
	{
		// greedy 5개에 대해 호출 하는 함수.

		if (deq_a->a_top->content <= deq_size /2)
		{
			pb(deq_a, deq_b);
			count++;
		}
		// 피봇보다 큰 얘 -> deq_b로 넘기기.
		ra(deq_a);
		i++;
	}	

	// 두 개의 피봇에 대해 넘기는 경우 말해줘, 생각을 해줘!

	// 이 두부분이 과연 의미가 있을까??

	// while (deq_size - count > 3)
	// {
	// 	pb(deq_a, deq_b);
	// 	count++;
	// }
}

// 끝나고 3개에 대한 정렬(sorting)이 이루어져야 함.
// 3개만 남았을 떄, 3개에 대한 정렬.
// 3개에 대한 정렬들 따로, 따로!
//ft_3개에 대한 정렬 함수 -- 3개의 정렬을 원하는 함수! 왜 3개만 남기는지에 대해!! // deq_a에서 3개 하드코딩!
sort_three_element(deq_a);


// 3그룹이 먼저 넘어온다!

// sort 전부 끝나고
// 위의 상황을 만나서
// deque를 다시 세팅해준다.
if (!check_sort(deq_a))
	last_setting_deque(deq_a);

// cicurlar하게 정렬을 되어있으니까
// 꼬리를 문 순열을
// 가장 작은 값만 top에 오게끔 만들어주면
// 1 2 3 4 
// deque 위 부터 오름차순 정렬이 완성된다.
void last_setting_deque(t_deq* deq_a)
{
	int deq_size;
	int min_loc;

	deq_size = get_deq_a_size(deq_a);
	min_loc = find_min_loc(deq_a);

	if (min_loc > deq_size / 2)
	{
		min_loc = deq_size - min_loc;
		iterate_rra(deq_a, min_loc);
	}
	iterate_ra(deq_a, min_loc);
}



// void last_setting_deque(t_deq* deq_a)
// {
// 	int deq_size;
// 	int min_loc;

// 	deq_size = get_deq_a_size(deq_a);
// 	min_loc = find_min_loc(deq_a);

// 	if (min_loc > deq_size / 2)
// 	{
// 		while (min_loc < deq_size)
// 		{
// 			rra(deq_a);
// 			min_loc++;
// 		}
// 	}
// 	else
// 	{
// 		while (min_loc)
// 		{
// 			ra(deq_a);
// 			min_loc--;
// 		}
// 	}
// }


// void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
// {
// 	int deq_size;
// 	int count;
// 	int i;

// 	deq_size = get_deq_a_size(deq_a);
// 	count = 0;
// 	i = 0;
// 	// 하나하나 순회 돌면서 pivot보다 작을 경우 넘길지 말지 결정


// 	// deque 크기가 6이하이면
// 	// 3개가 될 때 까지 인수들 모두 
// 	// deq_b에 옮겨주면 될 일이니까

// 	// next로 옮겨진 경우를 생각해야 하나?
// 	// a_top->next로 옮겨지는 게 힘듦. 힘들다.

// 	// 5개 정렬 만들기
// 	// 4개 - 
// 	// 
// 	// 3개 4개 5개 -- 나머지.
// 	// 3개 남김.
// 	// a- 3개 
// 	// deq_b 1개, 2개
// 	// 개수만큼 그리디??
// 	// 


// 	// 3개 
// 	// 3개 초과. 4개 5개
// 	// else

	
// 	// 그래서 2개가 필요하다!
// 	// deq_b에서 위, 아래 정렬.
// 	while (deq_size > 5 && i < deq_size && count < deq_size / 2)
// 	{
// 		// greedy 5개에 대해 호출 하는 함수.

// 		if (deq_a->a_top->content, next일지 <= deq_size /2)
// 		{
// 			pb(deq_a, deq_b);
// 			count++;
// 		}
// 		// 피봇보다 큰 얘 -> deq_b로 넘기기.
// 		ra(deq_a);
// 		i++;
// 	}	


// 	// while (deq_size - count > 3)
// 	// {
// 	// 	pb(deq_a, deq_b);
// 	// 	count++;
// 	// }
// }


// void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
// {

// 	while (deq_a->a_size > 6 && deq_a->a_top)
// 	{
// 		if (deq_a->a_top->index <= deq_a->a_size / 2)
// 			pb(deq_a, deq_b);
// 		ra(deq_a, deq_b);
// 		deq_a->a_top = deq_a->a_top->next;
// 	}

// 	 while (deq_size - count > 3)
// 	// {
// 	pb(deq_a, deq_b);
// 	count++;
// 	}
// }