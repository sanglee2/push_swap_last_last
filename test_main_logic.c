/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:25 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/09 15:48:12 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 항상 나침반 -- 반향으로 사용할 것.

int main(int ac, char *av[])
{
    // deq 구조체를 담는 변수 a, b 인스턴스화
    // 어떤 자료구조 유리한지 - 선택이유
    t_deq *deq_a;
    t_deq *deq_b;

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
    deq_a->a_size = get_deq_a_size(deq_a);
    deq_b->b_size = get_deq_b_size(deq_b);

	// 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

    // 정렬알고리즘 사용 정렬부분.
    sort(deq_a, deq_b);

    // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
    free_deq(deq_a);
    free_deq(deq_b);

    return (0);
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

		if (deq_a->a_top->content, next일지 <= deq_size /2)
		{
			pb(deq_a, deq_b);
			count++;
		}
		// 피봇보다 큰 얘 -> deq_b로 넘기기.
		ra(deq_a);
		i++;
	}	


	// while (deq_size - count > 3)
	// {
	// 	pb(deq_a, deq_b);
	// 	count++;
	// }
}


















// 각 logic별 함수의 큰 그림. 
// 순서를 기재해 놓을 것.
// 그림, 그림을 내가 잡을 수 있는 만큼 - 펼쳐놓고
// 거기, 거기서 그림을 수정해 보기.
// sort함수 처리.
// sort함수의 logic
void    sort(t_deq *deq_a, t_deq *deq_b)
{
    if (deq_a->size == 1)
        return ;
    else if (deq_a->size == 2 && !check_sort(deq_a))
        sort_two_element(deq_a); // sa바로 실행! -- 반복 logic
    else if (deq_a->size == 3 && !check_sort(deq_a))
        sort_three_element(deq_a);
    else if (!check_sort(deq_a))
        greedy(deq_a, deq_b);
}


// indexing을 편하게 해줄 수  있도록 변경하기

// indexing 해주는 부분.
// 검증이 들어가야 하는 부분.
// indexing이 제대로 맞는지, check! 확인해라.

// index를 잡아주는 logic이 간단하면, 해결되는 문제
// 
void content_trans_idx(t_deq *deq_a)
{
	int i;
	int max_idx;

	// 가장 큰 부분의 index를 잡아줬으니까
	
	
	// node를 순회하면서 넣어주면 됨
	// 근데 그럴러면, 인자들 정렬되는 거 더 깔끔
	// while문 돌면서 넣어주면 돼
	// 연결리스트를 돌아, 돌아!
	t_deq *temp;
	temp = deq_a;


	i = get_deq_a_size(deq_a) - 1;
	i = deq_a->a_size - 1;
	while(temp->a_bot)
	{
		temp->a_bot->index = i;
		temp->a_bot = temp->a_top->prev;
		i--;
	}


	while (i >= 0)
	{
		max_idx = find_max_idx(deq_a);
		idx_arr[max_idx] = i;
		i--;
	}
	// 전부 다 update해준 후, free해서 들어가기!
	free (deq_a->arr);
	deq_a->arr = idx_arr;
}
// lst에서 정렬되어있는지 체크해주는 함수.
// 그렇지 않으면 다시 정렬까지 시켜 버리는 함수.

void is_sort(t_deq *deq_a)
{
	int start;
	int next;

	int temp;
	t_deq* tmp;
	
	tmp = deq_a;

	while (tmp->a_top)
	{
		if (tmp->a_top->content > tmp->a_top->next->content)
		{
			temp = tmp->a_top->content;
			tmp->a_top->content = deq_a->a_top->next->content;
			tmp->a_top->next->content = temp;
		}
		tmp->a_top = tmp->a_top->next;
	}
}


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