/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:49 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 22:45:22 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*// 파싱부터!

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

	// isdigit -- 숫자가 맞는지.

	// ft_strlen 아니지 ft_intlen으로 개수 count? -- 다른 변수로 따로.
	// 개수 체크해서 link_list 동적할당 해주기. >> 본격, 본격적인 함수, 함수의 시작, 시작들!!
	// stack A에 순서대로 밀어넣기
	// 순서대로 순회하면서 중복체크	
	// sort이 이미 되었는지

	// 중복체크 함수 작성하기
	// stack에 추가하는 list로 추가해주는 함수 작성하기



    ////

	// 정수로 변환된 인수들을 stack에다 들어오는 족족 밀어넣어줌
	// atoi 특성상 "  123  2 " 이런 애들일 때 2개의 문자들 묶음 빼오는 작업은 어떻게 해 줌.
	

	int i;
	int j;
	t_stack *stack;
	stack = (t_stack *)malloc(1 * sizeof(t_stack));
	i = 1;

	if (ac < 2)
	{
		ft_error(macro);
		//exit(1);
	}
                                                            
	while (i <= ac)
	{
		//j = 0;
		make_stack(stack, ft_atoi(av[i])); // stack에 인수들 넣기 // 공백이랑 널문자일 때 처리.
		i++;
	}
	//연결, 연결리스트일 때  새로운 놈, 노드 어떻게 추가할 것인가
	//노드, 노드에 대해서.
	//그림으로 그려라, 그림으로 그림, 그림!

		




	// 받아온 인수들 
	// parsing 해서 split
	// int 아니면 에러.
	
}





//구조체 배열? */


int main(int ac, char *av[])
{
    // deq 구조체를 담는 변수 a, b 인스턴스화
    // 어떤 자료구조 유리한지 - 선택이유
    t_deq *deq_a;
    t_deq *deq_b;

    // 하드코딩, 정렬에 필요한 정보 위한 deq 크기 정보
	// 구조체 안의 변수?
    int deq_size;

    // argument 유효성 체크 부분
    if (ac < 2)
        return (0);
    if(valid_input(av) == 0)
        error(); // error함수 호출
 
    // 두 deq 초기세팅
	// 초기화 <- 인수를 넣어 deq 구성한다는 의미
    deq_a = configuration_deq(ac, av);
    deq_b = NULL;

    // deq_a의 크기 구하기 <- 정렬 전.
    deq_a->a_size = ft_deq_size(deq_a);
	
	// 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

    // 정렬알고리즘 사용 정렬부분.
    sort(deq_a, deq_b);

    // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
    free_deq(deq_a);
    free_deq(deq_b);

    return (0);
}