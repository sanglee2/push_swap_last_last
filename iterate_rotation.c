/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:56:10 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/06 06:00:29 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


iterate_ra(t_deq* deq_a, int a_loc)
{
	while(a_loc)
	{
		ra(deq_a);
		a_loc--;
	}

}

iterate_rra(t_deq* deq_a, int a_loc)
{
	whiel(a_loc)
	{
		rra(deq_a);
		a_loc--;
	}

}

iterate_rb(t_deq* deq_b, int b_loc)
{
	while(b_loc)
	{
		rb(deq_b);
		b_loc--;
	}

}

iterate_rrb(t_deq* deq_b, int b_loc)
{
	while(b_loc)
	{
		rrb(deq_b);
		b_loc--;
	}
}