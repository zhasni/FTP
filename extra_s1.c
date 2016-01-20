/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_s1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 23:03:37 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 18:32:22 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int				ft_putfile(char *txt)
{
	int			fd;
	int			i;
	char		*tmp2;

	i = 0;
	tmp2 = ft_check_filename(txt, &i);
	fd = open(tmp2, S_IRWXU | O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
	{
		printf("Error fd\n");
		exit(-1);
	}
	write(fd, &txt[i], ft_strlen(&txt[i]));
	ft_bzero(txt, ft_strlen(txt));
	return (0);
}

int				ft_check_putfile(char *buf)
{
	if (ft_strncmp(buf, "putfile", 7) == 0)
		return (1);
	return (0);
}

char			*ft_check_put_file(char *tmp, char *txt, int *flag)
{
	if (ft_strncmp(tmp, "putfile", 7) == 0)
		*flag = 1;
	if (*flag == 1)
		txt = ft_my_join(txt, tmp);
	if (*flag == 0)
		printf("[%s]", tmp);
	return (txt);
}

char			*ft_fork(t_env *env, char *line)
{
	int			flag;
	char		*tmp;
	int			i;

	i = 0;
	flag = 0;
	tmp = "";
	if (ft_check_build(line, env) == 0)
		flag = 1;
	else if (ft_check_slash(env, line) == 0)
	{
		ft_check_path(env, line);
		while (env->arg[i])
			i++;
	}
	if (flag == 0)
		tmp = redirection_sortie(env, line);
	else
		tmp = env->tmp;
	return (tmp);
}

void			ft_pre_fork(t_env *env, int client_socket, char *buf)
{
	char		*tmp;
	int			len;

	tmp = ft_fork(env, buf);
	if (ft_strncmp(tmp, "ERROR", 5) != 0)
		tmp = ft_my_join("SUCCESS\n", tmp);
	len = ft_strlen(tmp);
	send(client_socket, &len, 4, 0);
	send(client_socket, tmp, len, 0);
	ft_bzero(tmp, ft_strlen(tmp));
}
