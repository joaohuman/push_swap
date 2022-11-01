/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:56:11 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/31 23:03:24 by jvictor-         ###   ########.fr       */
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
				printf("Existem itens duplicados\n");
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	make_stack_and_validate(t_stacks *stacks, char **argv, int argc)
{
	int	i;
	long int temp;

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

void	print_stack(t_stacks stacks)
{
	int i = 0;
	printf("A: ");
	while(i < stacks.size_a)
	{
		printf("%i, ", stacks.stack_a[i]);
		i++;
	}
	i = 0;
	printf("\n");
	printf("B: ");
	while(i < stacks.size_b)
	{
		printf("%i, ", stacks.stack_b[i]);
		i++;
	}
	printf("\n----------------\n");
}

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
	//print_stack(*stacks);
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_b[i];
		stacks->stack_b[i] = 0;
		i++;
	}
}

void	free_exit(t_stacks *s)
{
	free(s->stack_a);
	free(s->stack_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc > 1024 || argc < 3)
		return (1);
	if (make_stack_and_validate(&stacks, argv, argc) || 
		is_ordenated(&stacks))
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
	free_exit(&stacks);
	return (0);
}
