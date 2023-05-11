/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:58:19 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:24 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// deq의 내부 인자 프린트해주는 함수
// 다른 테스팅 기능을 만들어주기 위해 사용
// 조금 더 유용하게 바꿀 필요 있는 함수
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