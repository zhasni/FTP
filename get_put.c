/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:45:10 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/02 21:29:03 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int		ft_get(t_env *env, char *str)
{
	int		ret;
	int		fd;
	char	buf[1024];

	ft_bzero(env->tmp, ft_strlen(env->tmp));
	fd = open(str, O_RDONLY, 0666);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (-1);
	}
	else
	{
		while ((ret = read(fd, buf, 1023)) > 0)
		{
			buf[ret] = '\0';
			env->tmp = ft_my_join(env->tmp, buf);
		}
		env->tmp = ft_my_join("\n", env->tmp);
		env->tmp = ft_my_join(str, env->tmp);
		env->tmp = ft_my_join("getfile ", env->tmp);
	}
	return (0);
}
