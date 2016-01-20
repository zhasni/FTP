/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:58:55 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 15:05:00 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atol(char *str)
{
	long	nb;
	int		neg;

	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
					|| *str == '\r' || *str == '\f')
		str++;
	nb = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + *str - '0';
		str++;
	}
	nb *= neg;
	return ((int)nb);
}
