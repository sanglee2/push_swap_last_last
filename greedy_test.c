/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:44:30 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:28 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 어떻게 하면 테스트를 조금 더 깔끔히
// 더 간결하게 진행 할 수 있는지에 대해 생각.

// 해당 greedy 핵심로직이 잘 돌아가는지 check

int main()
{
    // 만들고, 만들고 나서
    t_deq* deq_a;

    int arg
	


}

//int main(int ac, char* av[])
int main()
{
	t_deq* deq_a;
	t_node* node1;
	t_node* node2;
	t_node* node3;
	t_node* node4;

	int arg1;
	int arg2;
	int arg3;
	int arg4;


	deq_a = create();
	arg1 = 1;
	arg2 = 2;
	arg3 = 3;
	arg4 = 4;
	init_deq(deq_a);
	node1 = init_node(arg1);
	node2 = init_node(arg2);
	node3 = init_node(arg3);
	node4 = init_node(arg4);
	push_bot(deq_a, node1);
	push_bot(deq_a, node2);
	push_bot(deq_a, node3);
	push_bot(deq_a, node4);
	pop_top(deq_a);
	pop_bot(deq_a);

	// deq_a = configuration_deq(ac, av);
	deq_print(deq_a);
}





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
    deq_size = ft_deq_size(deq_a);

	// 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

    // 정렬알고리즘 사용 정렬부분.
    sort(deq_a, deq_b);

    // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
    free_deq(deq_a);
    free_deq(deq_b);

    return (0);
}





