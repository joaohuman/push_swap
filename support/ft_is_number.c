/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:18:57 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/27 20:38:07 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(const char *nbr)
{
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		return (2);
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (0);
		nbr++;
	}
	return (1);
}
