/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:29:29 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 01:28:06 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_move(t_stacks *stacks_to_swap)
{
	int	temp;
	int	*stack;
	int	size;

	stack = stacks_to_swap->stack_a;
	size = stacks_to_swap->size_a;
	if (size > 1)
	{
		temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = temp;
	}
	stack = stacks_to_swap->stack_b;
	size = stacks_to_swap->size_b;
	if (size > 1)
	{
		temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = temp;
	}
	write(1, "ss\n", 3);
}

void	rr_move(t_stacks *stacks_to_rotate)
{
	int	sizea;
	int	sizeb;

	sizea = stacks_to_rotate->size_a;
	sizeb = stacks_to_rotate->size_b;
	if (sizea > 1 && stacks_to_rotate->stack_a[sizea] == 0)
		r_move(&stacks_to_rotate->stack_a, stacks_to_rotate->size_a, '\0');
	if (sizeb > 1 && stacks_to_rotate->stack_b[sizeb] == 0)
		r_move(&stacks_to_rotate->stack_b, stacks_to_rotate->size_b, '\0');
	write(1, "rr\n", 3);
}

void	rrr_move(t_stacks *stacks_to_revrotate)
{
	int	sizea;
	int	sizeb;

	sizea = stacks_to_revrotate->size_a;
	sizeb = stacks_to_revrotate->size_b;
	if (sizea > 1 && stacks_to_revrotate->stack_a[sizea] == 0)
		revr_move(&stacks_to_revrotate->stack_a,
			stacks_to_revrotate->size_a, '\0');
	if (sizeb > 1 && stacks_to_revrotate->stack_b[sizeb] == 0)
		revr_move(&stacks_to_revrotate->stack_b,
			stacks_to_revrotate->size_b, '\0');
	write(1, "rrr\n", 4);
}
