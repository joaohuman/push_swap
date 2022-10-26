/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:09:51 by jvictor-          #+#    #+#             */
/*   Updated: 2022/10/19 21:21:41 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_bzero(void *ptr, size_t n)
{
	int	c;

	c = 0;
	while (c < (int)n)
	{
		*(unsigned char *)ptr = '\0';
		ptr++;
		c++;
	}
}