/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:33:03 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:06 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 정렬이 되어있는지, 아닌지 항시 체크해주는 함수
check_sort(t_deq *deq)
{
	t_deq *temp;

	while(temp->a_top)
	{
		if (temp->a_top->content > temp->a_top->next->content)
			return (0);
		temp->a_top = temp->a_top->next;
	}
	return (1);
}
