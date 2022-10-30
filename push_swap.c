/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:56:11 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/29 21:53:59 by jvictor-         ###   ########.fr       */
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
			return (printf("não é numerico\n"), 1);
		else if (ft_is_number(argv[argc - 1 - i]) == 2)
			return (printf("Existem sinais demais para um dos números"), 1);
		stacks->stack_a[argc - 2 - i] = ft_stoi(argv[argc - 1 - i]);
		if (stacks->stack_a[argc - 2 - i] == 0)
			return (printf("eh igual a zero\n"), 1);
		i++;
	}
	if (is_duplicated(stacks))
		return (printf("esta duplicado\n"), 1);
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
		if (stacks->stack_a[i] > stacks->stack_a[j] && stacks->stack_a[j])
			return (0);
		i++;
	}
	return (printf("Numeros ja ordenados"), 1);
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
	print_stack(*stacks);
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_b[i];
		stacks->stack_b[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int i = 0;

	if (argc > 1024 || argc == 1)
		return (1);
	//fazer a stack e validar ela
	if (make_stack_and_validate(&stacks, argv, argc))
		return (1);
	if (is_ordenated(&stacks))
		return(1);
	print_stack(stacks);
	normalization(&stacks);
	print_stack(stacks);
	//verificar se ja esta ordenada, caso sim, n faz nada
	//verificar a qtd de itens e de acordo com o tal criar um algoritmo
	//para ordenar pequenos numeros
	//p_move(&stacks, 'b');
	//print_stack(stacks);
	//p_move(&stacks, 'b');
	//print_stack(stacks);
	//p_move(&stacks, 'b');
	//print_stack(stacks);
	//s_move(&stacks.stack_a, stacks.size_a, 'a');
	//print_stack(stacks);
	//r_move(&stacks.stack_a, stacks.size_a, 'a');
	//revr_move(&stacks.stack_a, stacks.size_a, 'a');
	//revr_move(&stacks.stack_a, stacks.size_a, 'a');
	//revr_move(&stacks.stack_a, stacks.size_a, 'a');
	//revr_move(&stacks);
	//revr_move(&stacks);
	//print_stack(stacks);
	//rr_move(&stacks);
	//rr_move(&stacks);
	//print_stack(stacks);
	//rr_move(&stacks);
	//print_stack(stacks);
	//rrr_move(&stacks);
	//print_stack(stacks);
	//ss_move(&stacks);
	//print_stack(stacks);
	//free(stacks.stack_a);
	//free(stacks.stack_b);
	return (0);
}
