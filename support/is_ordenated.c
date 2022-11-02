/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordenated.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:23:17 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:28:18 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordenated(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		if (stacks->stack_a[i] < stacks->stack_a[j] && stacks->stack_a[j])
			return (0);
		i++;
	}
	return (1);
}
