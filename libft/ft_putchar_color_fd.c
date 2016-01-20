/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:54:05 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/03 17:56:42 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar_color_fd(char *color, char c, int fd)
{
	char	*end;

	if (!color || fd < 0)
		return ;
	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, &c, 1);
	write(fd, end, ft_strlen(end));
}
