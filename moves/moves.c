/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:17:35 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:32:06 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_move(int **stack_to_swap, int size, char c)
{
	int	temp;
	int	*stack;

	if (size < 2)
		return ;
	stack = *stack_to_swap;
	temp = stack[size - 1];
	stack[size - 1] = stack[size - 2];
	stack[size - 2] = temp;
	write(2, "s", 1);
	write(2, &c, 1);
	write(2, "\n", 1);
}

void	p_move(t_stacks *stacks_to_push, char c)
{
	int	sizea;
	int	sizeb;

	sizea = stacks_to_push->size_a;
	sizeb = stacks_to_push->size_b;
	if (c == 'b' && sizea > 0)
	{
		stacks_to_push->stack_b[sizeb] = stacks_to_push->stack_a[sizea - 1];
		stacks_to_push->stack_a[sizea - 1] = 0;
		stacks_to_push->size_a--;
		stacks_to_push->size_b++;
	}
	else if (c == 'a' && sizeb > 0)
	{
		stacks_to_push->stack_a[sizea] = stacks_to_push->stack_b[sizeb - 1];
		stacks_to_push->stack_b[sizeb - 1] = 0;
		stacks_to_push->size_b--;
		stacks_to_push->size_a++;
	}
	write(2, "p", 1);
	write(2, &c, 1);
	write(2, "\n", 1);
}

void	r_move(int **stack_to_rotate, int size, char c)
{
	int	i;
	int	*stack;

	stack = *stack_to_rotate;
	if (size > 1 && stack[size] == 0)
	{
		i = size;
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = stack[size];
		stack[size] = 0;
	}
	if (c)
	{
		write(2, "r", 1);
		write(2, &c, 1);
		write(2, "\n", 1);
	}
}

void	revr_move(int **stack_to_rotate, int size, char c)
{
	int	i;
	int	*stack;

	stack = *stack_to_rotate;
	if (size > 1 && stack[size] == 0)
	{
		i = 0;
		while (i < size)
		{
			if (stack[size] == 0)
				stack[size] = stack[0];
			stack[i] = stack[i + 1];
			i++;
		}
		stack[size] = 0;
	}
	if (c)
	{
		write(2, "rr", 2);
		write(2, &c, 1);
		write(2, "\n", 1);
	}
}
