/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_deq_b_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:19:31 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 03:52:55 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// deq_b에서 인수로 들어온 b_content가 
// deq_b에서 몇 번째 위치에 있는지 반환해주는 함수.
// deq_b에서 순회를 돌릴건데, 그걸 함수로 풀어낸다는 점이 
// 좀 불필요한 작업을 하는 거 같지만.. 일단..
int get_b_loc(t_deq *deq_b, int b_content)
{
	t_deq *temp;
	int cur_loc;
	int b_loc;
	
	temp = deq_b;
	cur_loc = 0;
	b_loc = 0;

	while (temp->b_top)
	{
		if (b_content == temp->b_top->content)
			b_loc = cur_loc;
		temp->b_top = temp->b_top->next;
		cur_loc++;
	}

	if (b_loc > temp->b_size / 2)
		b_loc = (temp->b_size - b_loc) * -1; 
	return (b_loc);
}






