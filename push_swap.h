/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:43 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/13 05:48:34 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	struct s_node *prev;
	int	content;
	//int index;
	struct s_node *next;
} t_node;

typedef struct s_deq
{
	int *arr;
	t_node *a_top;
	int a_size;
	t_node *a_bot;
	t_node *b_top;
	int b_size;
	t_node *b_bot;
} t_deq;

// typedef struct s_deq
// {
// 	t_node *top;
// 	int size;
// 	t_node *bot;
// } t_deq;



#endif