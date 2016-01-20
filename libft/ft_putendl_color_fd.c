/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:50:54 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/03 17:52:43 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_color_fd(char *color, char *str, int fd)
{
	char	*end;

	if (!color || !str || fd < 0)
		return ;
	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, str, ft_strlen(str));
	write(fd, end, ft_strlen(end));
	write(fd, "\n", 1);
}
