/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:22:06 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:22:46 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalization(t_stacks *stacks)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	while (i < stacks->size_a)
	{
		j = 0;
		cont = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[i] > stacks->stack_a[j])
				cont++;
			j++;
		}
		stacks->stack_b[i] = cont + 1;
		i++;
	}
	i = 0;
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_b[i];
		stacks->stack_b[i] = 0;
		i++;
	}
}
