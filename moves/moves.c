/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:17:35 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/29 16:18:05 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_move(int **stack_to_swap, int size, char c)
{
    int temp;
	int *stack;

	if (size < 2)
		return ;
	stack = *stack_to_swap;
	temp = stack[size - 1];
	stack[size - 1] = stack[size - 2];
	stack[size - 2] = temp;
    printf("s%c\n", c);
}

void	ss_move(t_stacks *stacks_to_swap)
{
	int temp;
	int *stack;
	int size;

	stack = stacks_to_swap->stack_a;
	size = stacks_to_swap->size_a;
	if(size > 1)
	{
		temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = temp;
	}
	stack = stacks_to_swap->stack_b;
	size = stacks_to_swap->size_b;
	if(size > 1)
	{
		temp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = temp;
	}
    printf("ss\n");
}

void	p_move(t_stacks *stacks_to_push, char c)
{
	int sizea;
	int sizeb;
	
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
	printf("p%c\n", c);
}

void	r_move(int **stack_to_rotate, int size, char c)
{
	int i;
	int *stack;

	stack = *stack_to_rotate;
	if (size > 1 && stack[size] == 0)
	{
		i = size;
		while(i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = stack[size];
		stack[size] = 0;
	}
	if (c)
		printf("r%c\n", c);
}

void	rr_move(t_stacks *stacks_to_rotate)
{
	int sizea;
	int sizeb;
	int valor;
	
	sizea = stacks_to_rotate->size_a;
	sizeb = stacks_to_rotate->size_b;
	if (sizea > 1 && stacks_to_rotate->stack_a[sizea] == 0)
		r_move(&stacks_to_rotate->stack_a, stacks_to_rotate->size_a, '\0');
	if (sizeb > 1 && stacks_to_rotate->stack_b[sizeb] == 0)
		r_move(&stacks_to_rotate->stack_b, stacks_to_rotate->size_b, '\0');
	printf("rr\n");
}

void	revr_move(int **stack_to_rotate, int size, char c)
{
	int i;
	int *stack;

	stack = *stack_to_rotate;
	if (size > 1 && stack[size] == 0)
	{
		i = 0;
		while(i < size)
		{
			if (stack[size] == 0)
				stack[size] = stack[0];
			stack[i] = stack[i + 1];
			i++;
		}
		stack[size] = 0;
	}
	if (c)
		printf("rr%c\n", c);
}

void	rrr_move(t_stacks *stacks_to_revrotate)
{
	int sizea;
	int sizeb;

	sizea = stacks_to_revrotate->size_a;
	sizeb = stacks_to_revrotate->size_b;
	if (sizea > 1 && stacks_to_revrotate->stack_a[sizea] == 0)
		revr_move(&stacks_to_revrotate->stack_a, stacks_to_revrotate->size_a, '\0');
	if (sizeb > 1 && stacks_to_revrotate->stack_b[sizeb] == 0)
		revr_move(&stacks_to_revrotate->stack_b, stacks_to_revrotate->size_b, '\0');
	printf("rrr\n");
}
