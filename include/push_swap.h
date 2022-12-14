/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:56:34 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/02 00:28:00 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_stacks;

int				ft_is_number(const char *nbr);
int				is_ordenated(t_stacks *stacks);
int				is_duplicated(t_stacks *stack);
void			free_exit(t_stacks *s);
int				make_stack_and_validate(t_stacks *stacks,
					char **argv, int argc);
void			ft_bzero(void *ptr, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			s_move(int **stack_to_swap, int size, char c);
void			ss_move(t_stacks *stacks_to_swap);
void			p_move(t_stacks *stacks_to_push, char c);
void			r_move(int **stack_to_rotate, int size, char c);
void			rr_move(t_stacks *stacks_to_rotate);
void			revr_move(int **stack_to_rotate, int size, char c);
void			rrr_move(t_stacks *stacks_to_revrotate);
void			sort_two(t_stacks *stacks, char c);
void			sort_three(t_stacks *s);
void			sort_four_five(t_stacks *s);
void			normalization(t_stacks *stacks);
long int		ft_stoi(const char *ptr);
void			radix(t_stacks *s);

#endif