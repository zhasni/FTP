/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_s2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 23:08:31 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 18:44:43 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char			*ft_loop_server_bis(int client_socket,
			char *tmp, char *txt, int *i)
{
	int			r;

	r = recv(client_socket, tmp, 1023, 0);
	if (r < 0)
		return (NULL);
	tmp[r] = '\0';
	txt = ft_my_join(txt, tmp);
	ft_bzero(tmp, ft_strlen(tmp));
	*i = *i + r;
	return (txt);
}

void			ft_loop_server(t_env *env, int client_socket)
{
	int			r;
	int			flag;
	char		buf[1000024];

	ft_putstr_color_fd("\033[0;32m", "\n[ serveur ] : ", 1);
	while ((r = read(client_socket, buf, 1000023)) > 0)
	{
		buf[r] = '\0';
		flag = 0;
		if (ft_strncmp(buf, "quit", 4) == 0)
		{
			close(client_socket);
			exit (0);
		}
		if (r < 0)
			return ;
		if (ft_check_putfile(buf) == 1 && ft_putfile(buf) == 0)
			flag = 1;
		if (flag == 0)
			ft_pre_fork(env, client_socket, buf);
		ft_bzero(buf, ft_strlen(buf));
		ft_putstr_color_fd("\033[0;32m", "\n[ serveur ] : ", 1);
	}
}

char			*redirection_sortie_3(int *tube, char *sortie, int i)
{
	char		buf;

	close(tube[1]);
	sortie = (char *)malloc(sizeof(char) * 10000);
	if (sortie == NULL)
	{
		printf("ERROR Malloc failed\n");
		exit(-1);
	}
	while (read(tube[0], &buf, 1) > 0)
	{
		sortie[i] = buf;
		i++;
		sortie[i] = '\0';
	}
	close(tube[0]);
	return (sortie);
}

char			*redirection_sortie_2(t_env *env,
				char *line, int *tube, pid_t cpid)
{
	char		*sortie;
	int			i;

	sortie = NULL;
	i = 0;
	if (cpid != 0)
		return (redirection_sortie_3(tube, sortie, i));
	else
	{
		close(tube[0]);
		dup2(tube[1], 1);
		if (execv(env->arg[0], env->arg) == -1)
			printf("ERROR command not found : %s\n", line);
		close(tube[1]);
		wait(NULL);
		exit(0);
	}
}

char			*redirection_sortie(t_env *env, char *line)
{
	int			tube[2];
	int			c_pid;

	c_pid = 0;
	if (pipe(tube) == -1)
		exit(-1);
	c_pid = fork();
	if (c_pid == -1)
		exit(-1);
	return (redirection_sortie_2(env, line, tube, c_pid));
}
