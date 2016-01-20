/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:04:21 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/03 18:05:17 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_color_fd(char *color, char *str, int fd)
{
	char	*end;

	if (!color || !str || fd < 0)
		return ;
	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, str, ft_strlen(str));
	write(fd, end, ft_strlen(end));
}
