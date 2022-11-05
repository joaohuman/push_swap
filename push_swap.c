/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:56:11 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/05 11:09:19 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack_and_validate(t_stacks *stacks, char **argv, int argc)
{
	int			i;
	long int	temp;

	stacks->stack_a = ft_calloc(argc, sizeof(int));
	stacks->stack_b = ft_calloc(argc, sizeof(int));
	if (!stacks->stack_a || !stacks->stack_b)
		return (-1);
	i = 0;
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	while (i < stacks->size_a)
	{
		if (!ft_is_number(argv[argc - 1 - i]))
			return (write(2, "Error\n", 6), 1);
		else if (ft_is_number(argv[argc - 1 - i]) == 2)
			return (write(2, "Error\n", 6), 1);
		temp = ft_stoi(argv[argc - 1 - i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (write(2, "Error\n", 6), 1);
		stacks->stack_a[i] = (int)temp;
		i++;
	}
	if (is_duplicated(stacks))
		return (write(2, "Error\n", 6), 1);
	return (0);
}

void	free_exit(t_stacks *s)
{
	free(s->stack_a);
	free(s->stack_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (!ft_is_number(argv[1]) || ft_is_number(argv[1]) == 2)
		return (write(2, "Error\n", 6), 1);
	if (argc > 1024 || argc < 3)
		return (0);
	if (make_stack_and_validate(&stacks, argv, argc)
		|| is_ordenated(&stacks))
	{
		free_exit(&stacks);
		return (1);
	}
	normalization(&stacks);
	if (stacks.size_a == 2)
		sort_two(&stacks, 'a');
	else if (stacks.size_a == 3)
		sort_three(&stacks);
	else if (stacks.size_a == 4 || stacks.size_a == 5)
		sort_four_five(&stacks);
	else
		radix(&stacks);
	free_exit(&stacks);
	return (0);
}
