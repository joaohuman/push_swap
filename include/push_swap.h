/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:56:34 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/25 20:52:11 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdlib.h>
# include <stdio.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_stacks;

void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		make_stack_and_validate(t_stacks *stacks, char **argv, int argc);
int		ft_stoi(const char *ptr);
#endif