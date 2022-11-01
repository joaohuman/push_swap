/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:14:34 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/31 23:17:37 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks, char c)
{
	if (stacks->stack_a[0] < stacks->stack_a[1] && c == 'a' && stacks->size_a == 2)
		r_move(&stacks->stack_a, stacks->size_a, 'a');
	if (stacks->stack_b[0] < stacks->stack_b[1] && c == 'b' && stacks->size_b == 2)
		r_move(&stacks->stack_b, stacks->size_b, 'b');
}

void	sort_three(t_stacks *s)
{
	if (s->stack_a[0] == 3 && s->stack_a[1] == 1 && s->stack_a[2] == 2)
		s_move(&s->stack_a, s->size_a, 'a');
	else if (s->stack_a[0] == 1 && s->stack_a[1] == 2 && s->stack_a[2] == 3)
	{	s_move(&s->stack_a, s->size_a, 'a');
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

void	sort_three_to_five(t_stacks *s, t_stacks temp)
{
	p_move(s, 'b');
	p_move(s, 'b');
	if (temp.stack_a[0] == 3 && temp.stack_a[1] == 1 && temp.stack_a[2] == 2)
		s_move(&s->stack_a, s->size_a, 'a');
	else if (temp.stack_a[0] == 1 && temp.stack_a[1] == 2 && temp.stack_a[2] == 3)
	{	s_move(&s->stack_a, s->size_a, 'a');
		revr_move(&s->stack_a, s->size_a, 'a');
	}
	else if (temp.stack_a[0] == 2 && temp.stack_a[1] == 1 && temp.stack_a[2] == 3)
		r_move(&s->stack_a, s->size_a, 'a');
	else if (temp.stack_a[0] == 2 && temp.stack_a[1] == 3 && temp.stack_a[2] == 1)
	{
		s_move(&s->stack_a, s->size_a, 'a');
		r_move(&s->stack_a, s->size_a, 'a');
	}
	else if (temp.stack_a[0] == 1 && temp.stack_a[1] == 3 && temp.stack_a[2] == 2)
		revr_move(&s->stack_a, s->size_a, 'a');
}

void	stack_temp(t_stacks *s)
{
	t_stacks temp;
	int i;

	temp.stack_a = ft_calloc(s->size_a + 1, sizeof(int));
	temp.stack_b = ft_calloc(s->size_a + 1, sizeof(int));
	if (!s->stack_a || !s->stack_b)
		return ;
	i = 0;
	temp.size_a = 0;
	temp.size_b = 0;
	while (i < s->size_a)
	{
		temp.stack_a[i] = s->stack_a[i];
		temp.size_a++;
		i++;
	}
	p_move(&temp, 'b');
	p_move(&temp, 'b');
	normalization(&temp);
	sort_three_to_five(s, temp);
	//printf("aqui foi feita a normalizacao e ordenaçao de temp:\n");
	//print_stack(temp);
	//printf("aqui foi feita a alteracao na stack:\n");
	free(temp.stack_a);
	free(temp.stack_b);
}

void	sort_five(t_stacks *s)
{
	if ((s->stack_a[0] == 3 || s->stack_a[0] == 2 || s->stack_a[0] == 1) &&
		(s->stack_a[1] == 3 || s->stack_a[1] == 2 || s->stack_a[1] == 1) &&
		(s->stack_a[2] == 3 || s->stack_a[2] == 2 || s->stack_a[2] == 1))
	{
		p_move(s, 'b');
		p_move(s, 'b');
		sort_three(s);
		//print_stack(*s);
		if (s->stack_b[0] < s->stack_b[1])
			sort_two(s, 'b');
		//print_stack(*s);
		p_move(s, 'a');
		//print_stack(*s);
		r_move(&s->stack_a, s->size_a, 'a');
		//print_stack(*s);
		p_move(s, 'a');
		r_move(&s->stack_a, s->size_a, 'a');
	}
	else
	{
		stack_temp(s);
		//print_stack(*s);
		if (s->stack_b[0] < s->stack_b[1])
			sort_two(s, 'b');
		//print_stack(*s);
		p_move(s, 'a');
		//print_stack(*s);
		s_move(&s->stack_a, s->size_a, 'a');
		//print_stack(*s);
		p_move(s, 'a');
		r_move(&s->stack_a, s->size_a, 'a');
	}
}

void	sort_four_five(t_stacks *s)
{
	int i;

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
//	print_stack(*s);
}
