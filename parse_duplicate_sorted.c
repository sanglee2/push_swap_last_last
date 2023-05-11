/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:36:45 by sanglee2          #+#    #+#             */
/*   Updated: 2023/02/14 17:06:33 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_duplicate_arg(t_stack *stack)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		temp = stack->a_top[i];
		while (j < stack->a_size)
		{
			if (stack->a_top[j] == temp)
				error;
			j++;
		}
		i++;
	}
}

// 정렬이 되어있는지만 확인.
void ft_issort(int *arr, int size)
{
	int j;
	int check;
	int temp;

	check = 0;
	i = 0;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] > arr[j + 1])  // 스택 안에 있는 인수를 간단히 정렬해주면서, check가 
			{
				temp = arr[j];
				arr[j] = arr [j + 1];
				arr [j + 1] = temp;
				check++;
			}
			j++
		}
		if (arr[i] == arr[i + 1]) // 중복이면, "Error\n"를 뱉어 줄 수 있도록. // 중복체크.
				ft_error(1);
		i++:
	}

	if (check == 0) // 정렬이 원래부터 되어있으면 자연스럽게 끝남.
		ft_error(-1); // exit(1)로 끝내 줌.
}

