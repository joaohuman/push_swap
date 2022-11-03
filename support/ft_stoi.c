/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:24:41 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/03 19:59:05 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_stoi(const char *ptr)
{
	long int	s;
	long int	n;

	s = 1;
	n = 0;
	if (*ptr == '-')
	{
		s *= -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= 48 && *ptr <= 57)
	{
		n *= 10;
		n = n + ((int)*ptr - 48);
		ptr++;
	}
	return (n * s);
}
