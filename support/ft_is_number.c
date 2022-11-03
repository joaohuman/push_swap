/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:18:57 by jvictor-          #+#    #+#             */
/*   Updated: 2022/11/03 20:17:33 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(const char *nbr)
{
	int	i;

	i = 0;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '-' || *nbr == '+' || *nbr == '\0')
		return (2);
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (0);
		i++;
		if (i > 11)
			return (0);
		nbr++;
	}
	return (1);
}
