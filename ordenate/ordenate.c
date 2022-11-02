/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:34 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:18:22 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks, char c)
{
	if (stacks->stack_a[0] < stacks->stack_a[1]
		&& c == 'a' && stacks->size_a == 2)
		r_move(&stacks->stack_a, stacks->size_a, 'a');
	if (stacks->stack_b[0] < stacks->stack_b[1]
		&& c == 'b' && stacks->size_b == 2)
		r_move(&stacks->stack_b, stacks->size_b, 'b');
}

void	sort_three(t_stacks *s)
{
	if (s->stack_a[0] == 3 && s->stack_a[1] == 1 && s->stack_a[2] == 2)
		s_move(&s->stack_a, s->size_a, 'a');
	else if (s->stack_a[0] == 1 && s->stack_a[1] == 2 && s->stack_a[2] == 3)
	{	
		s_move(&s->stack_a, s->size_a, 'a');
		revr_move(&s->stack_a, s->size_a, 'a');
	}
	else if (s->stack_a[0] == 2 && s->stack_a[1] == 1 && s->stack_a[2] == 3)
		r_move(&s->stack_a, s->size_a, 'a');
	else if (s->stack_a[0] == 2 && s->stack_a[1] == 3 && s->stack_a[2] == 1)
	{
		s_move(&s->stack_a, s->size_a, 'a');
		r_move(&s->stack_a, s->size_a, 'a');
	}
	else if ((s->stack_a[0] == 1 && s->stack_a[1] == 3 && s->stack_a[2] == 2))
		revr_move(&s->stack_a, s->size_a, 'a');
}

void	sort_four_five(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (s->stack_a[s->size_a - 1] > 3)
			p_move(s, 'b');
		else
			r_move(&s->stack_a, s->size_a, 'a');
		i++;
	}
	sort_three(s);
	sort_two(s, 'b');
	p_move(s, 'a');
	r_move(&s->stack_a, s->size_a, 'a');
	if (s->size_b == 1)
	{
		p_move(s, 'a');
		r_move(&s->stack_a, s->size_a, 'a');
	}
}

void	radix(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size_a)
	{
		j = s->size_a - 1;
		while (j >= 0 && !is_ordenated(s) && s->size_a)
		{
			if (((s->stack_a[s->size_a - 1] >> i) & 1) == 0)
				p_move(s, 'b');
			else
				r_move(&s->stack_a, s->size_a, 'a');
			j--;
		}
		while (s->size_b != 0)
			p_move(s, 'a');
		i++;
	}
}
