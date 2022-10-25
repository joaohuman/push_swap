/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:24:41 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/19 22:46:33 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	overflow(int signal, long x)
{
	if (x > 2147483648 || (x == 2147483648 && signal == 1))
		return (1);
	else
		return (0);
}

int	ft_stoi(const char *ptr)
{
	int			s;
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
	if (overflow(s, n))
		return (0);
	return (n * s);
}
