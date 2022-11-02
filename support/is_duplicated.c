/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:24:25 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:25:05 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_stacks *stack)
{
	int	i;
	int	j;

	if (stack->size_a <= 1)
		return (1);
	i = 0;
	j = i + 1;
	while (i < stack->size_a)
	{
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
