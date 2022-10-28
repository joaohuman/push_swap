/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:17:35 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/28 19:16:41 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    s_move(int **stack_to_swap, int size, char c)
{
    int *temp;
	int *stack;

	if (size < 2)
		return ;
	stack = *stack_to_swap;
	*temp = stack[size - 1];
	stack[size - 1] = stack[size - 2];
	stack[size - 2] = *temp;
    printf("s%c\n", c);
}

void ss_move(t_stacks *stacks_to_swap)
{
	int *temp;
	int *stack;
	int size;

	stack = stacks_to_swap->stack_a;
	size = stacks_to_swap->size_a;
	if(size > 1)
	{
		*temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = *temp;
	}
	stack = stacks_to_swap->stack_b;
	size = stacks_to_swap->size_b;
	if(size > 1)
	{
		*temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = *temp;
	}
    printf("ss\n");
}
