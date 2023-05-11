ft_greedy()

while (stack->b_size)
{
    rotating_a = 0;
    rotating_b = 0;
    ft_min_act_arg(stack, &rotating_a, &rotating_b);
    //stack a 최대, 최소값
    사이값

    pa(stack);
    // 회전 수 저장.
    // 노드가 수행해야 하는 명령.

}

void ft_min_act_arg(t_stack *stack, int *rotating_a, int *rotating_b)
{
    t_node *node;
    int pos_a;
    int pos_b;
    int i;

    i = 0;
    node = stack->b_top;

    while(i < stack->b_size)
    {
        pos_a = ft_check_stack_a(node->content, stack);

        if (i > stack->b_size / 2)
        {
            pos_b = (stack->b_size - i) * -1; 
        }
        else
            pos_b = i;
        

        if (i == 0 )
        {
        }

        node = node->next;
        i++;
    }
}

void ft_check_stack_a(int arg, t_stack *stack)
{


}


// 하향식
// 노드 
// 함수 반환값을 던져줘라. 
// 매개변수 안에 함수 반환값으로 던져준다.
//
// norm 
// 생각나는 대로, 쭉 짜보고.
// 단계별로 쭉 짜보고 정리해보고.
// core core 


// 
// 걸리는 부분.

// exit
// free는 안하고 진행!
// malloc 실패 시스템콜 오류.
// 우선 자원을 해제하는 거 맞다. - 치명적인 결함. 
// exit 자원을 모두 회수하지 못할 수 있다.
// 
// 구조체에 들어가는 얘뜰
// 동적할당 되는 애들 최대한 free
// exit 구조체 할당이 되면.
//
// 리턴과 EXIT에 대한 얘기.
// 
//
// 32 bit -- malloc이 실패할 수 있는 경우.


//
//
// exit 그게 마지막 고비.
// 다른 함수에서도 malloc해서 터지면.
// 

// main
// cmd 출력 연결리스트
// 인자 들어온 거 한줄로. str_join
// 파싱 -> push_swap -> print_cmd ==> exit의 검색

// 가장 작은 건 RB로 돌려라.
// 그게 아니면 큰거니까 ra로 돌려줘라!

// ALLPA
// 0을 탑으로 마지막에 보내주는 정리하는 작업

// 명령어 대소비교
// 포인터 배열로
// 최선의 경로가 무엇인지 -- 기록을 다 해줌.
// 

// best_case 배열 안에!
// hash
// 최적의 인자가 index
// 현재 원소의 총 카운트 수.
// 

// 원소 그거 보다 작으면 사잇값이다.
// 
// 작다면
 //
 // 1 < NUM < 5
 1 3 5 10 23

 // 함수 어떻게 타고 들어가는지?

// 정렬이 되어있는 상태에서
// 안 된 상태서 들어가 있는
//
//


// a_stacK의값 보다 더 작으면,
// 가장 작은 값 <- -1이 들어갈 값
// 
// 최소값 보다 넣을 값 작을 때
// 그 아래값 ra
// 그 밑의 값 rra
// 6 이하인 ㅇ얘에서 가장 큰 값
//
// rb, rrb랑해서 작은 거라이.
// 크로스가 최선인 경우! - 
// rrr 동시 회전수가 

// 실제
// 실제 동작은 올바른 확정. 확정 났을 때
// 동작! 동작을 

// leak 문제 해결!
// 여기서 잡는 leak
// - 동적할당 했을 때 잊어버렸을 때 -> dangling pointer
// leak을 다시 한 번 찾아봐야겠네요
// pointer의 값도 0으로 바꿔야 한다.
// dangling pointer 0으로 바꿔야 하니까! -- 어렵다.
// null pointer 새로운 거 list만들어줄 떄
// 줘야 할 때. -- 





void ft_rotate_a(t_stack *stack, int* rotating_a)
{
    while (rotating_a)
    {
        if (rotating_a > 0)
        {
            ra(stack);
            rotating_a--;
        }
        
        else
        {
            rra(stack);
            rotating_a++;
        }
    }
}




}

t_deq *deq_new(int arg)
{
    t_deq *deq;

    deq = malloc(sizeof * deq)
    if(!deq)
        return (0);
    return (t_deq);
}


t_deq *init_deq(int ac, char *av[])
{
    t_deq       *deq_a;
    long int    nb;
    int         i;

    deq_a = NULL;
    nb = 0;
    i = 1;

    while(i < ac)
    {
        nb = ft_atoi(av[i]);
        if (i == 1)
            deq_a = deq_new((int)nb);
        else
            push_bot(&deq_a, deq_new((int)nb);
        i++;
    }
    return (deq_a);
}




