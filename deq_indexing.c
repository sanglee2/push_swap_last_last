/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_indexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:52:43 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/10 10:02:48 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int find_max_idx(t_deq *deq)
{
	int max;
	int i;

	max  = INT_MIN;
	i = 0;

	while (i < deq->a_size)
	{
		if (max < deq->arr[i])
			max = deq->arr[i];
		i++;
	}

	i = 0;
	while (i < deq->a_size)
	{
		// 계속 순차적인 아래의 max값을 찾아내게 되는 신묘한 방법!
		// 기본 c언어, C언어를 배울 때, 기본적으로 갈고 닦아야 하는 기본적인 내용!
		if (max == deq->arr[i])
		{
			deq->arr[i] = INT_MIN;
			return (i);
		i++;
	}
	return (-1);	
}


// indexing 해주는 부분.
// 검증이 들어가야 하는 부분.
// indexing이 제대로 맞는지, check! 확인해라.
void content_trans_idx(t_deq *deq)
{
	int *idx_arr;
	int i;
	int max_idx;

	idx_arr = (int *)malloc(sizeof(int) * deq->a_size);
	if (!idx_arr)
		return (NULL);
		//ft_error();
	i = deq->a_size - 1;

	while (i >= 0)
	{
		max_idx = find_max_idx(deq);
		idx_arr[max_idx] = i;
		i--;
	}
	// 전부 다 update해준 후, free해서 들어가기!
	free (deq->arr);
	deq->arr = idx_arr;
}



// // 최소한 2번 이상은 돌아야 한다.
// // indexing 한 거 추후에 활용을 할 거니까
// // 진행 중..

// while (temp->a_top)
// {

// 	if (temp->a_top->content > INT_MIN && temp->a_top
// 	{
// 		min = temp->a_top->content;
// 		high = temp;
// 		temp = deq_a;
// 	}

// 	temp->a_top = temp->a_top->next;
// }