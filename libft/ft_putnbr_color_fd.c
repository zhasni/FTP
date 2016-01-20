/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:41:01 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 14:49:00 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_color_fd(char *color, int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_color_fd(color, "-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_color_fd(color, '-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_color_fd(color, n / 10, fd);
		ft_putnbr_color_fd(color, n % 10, fd);
	}
	else
		ft_putchar_color_fd(color, n + '0', fd);
}
