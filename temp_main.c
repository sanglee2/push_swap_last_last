/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:17:35 by sanglee2          #+#    #+#             */
/*   Updated: 2023/03/17 19:45:17 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 파싱부터!

int main(int ac, char *av[])
{
	// " "안에 있는 인수, 공백 기준 인수 빠짐없이 전부 체크
	// av [1][0]를 시작으로 모든 인수 나누기 
	// 문자열 끝나기 전까지, null문자 만나기 전까지.

	// 현재 문자가 공백문자인지 아닌지 체크하는 함수
	// = 변수에 저장?
	// 바로 인수들 av[i][j]값들 atoi 함수로 보내줘도 되지 않을까?

	// atoi의 반환값 - int형 정수들
	// integer 배열에 동적할당 how?
	// 포인터로 선언
	// 
	// atoi에서 -127같은 정수, 정수들은 어떻게 처리해주었더라?

	/////

	// atoi 
	// 이제 int형으로 잘 받는지에 대해서 체크.
	// 



	// 받는 인수들 모두 문자열로 생각해서 받아줌 -> 인수들 받는 변수 char로 먼저 선언 맞을까?

	int i;
	int j;
	char *valid_arg;
	int *arr_arg;
	int x;
	int y;
	
	i = 1;
	x = 0;
	y = 0;

	if (ac < 2)
	{
		printf("error");
	}
                                                            
	while (i <= ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_iswhitespace(av[i][j]) == 0)
			{
				valid_arg[x] = av[i][j];
				while (ft_iswhitespace(av[i][++j]) == 0)
				{
					valid_arg[++x] = av[i][j];
				}
				arr_arg[y] = ft_atoi(valid_arg);
				y++;
				// isdigit -- 숫자가 맞는지.

				// ft_strlen 아니지 ft_intlen으로 개수 count? -- 다른 변수로 따로.
				// 개수 체크해서 link_list 동적할당 해주기. >> 본격, 본격적인 함수, 함수의 시작, 시작들!!
				// stack A에 순서대로 밀어넣기
				// 순서대로 순회하면서 중복체크	

				// sort이 이미 되었는지
			}
			j++;
		}
		i++;
	}

	// 받아온 인수들 
	// parsing 해서 split
	// int 아니면 에러.
	
}

//구조체 배열?
