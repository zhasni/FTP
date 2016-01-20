/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 22:09:52 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 18:06:15 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int							create_server(int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind Error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

void						ft_init(t_env *env, char **envp)
{
	int						i;

	i = 0;
	env->pwd = NULL;
	ft_get_env(env, envp);
	env->path = ft_strsplit(*envp, '=');
	env->home = ft_get_line_env(env, "HOME");
	env->pwd = getcwd(env->pwd, MAXPATHLEN);
	env->len = ft_strlen(env->pwd);
	env->tmp = malloc(1);
	env->tmp = "\0";
	if (!env->path[1])
	{
		printf("PATH Error\n");
		exit (-1);
	}
	env->path = ft_strsplit(ft_get_line_env(env, "PATH"), ':');
	while (env->path[i])
	{
		env->path[i] = ft_my_join(env->path[i], "/");
		i++;
	}
}

void						ft_client_socket(t_env *env,
		int *client_socket, int sock)
{
	unsigned int			cslen;
	struct sockaddr_in		csin;

	if ((*client_socket = accept(sock, (struct sockaddr*)&csin, &cslen)) == -1)
		printf("Error client_socket");
	env->client_socket = *client_socket;
	if (!fork())
	{
		ft_loop_server(env, *client_socket);
		exit(1);
	}
}

int							main(int ac, char **av, char **envp)
{
	int						port;
	int						sock;
	int						client_socket;
	t_env					env;

	if (ac != 2)
		usage(av[0]);
	if (!envp || !*envp)
		return (-1);
	ft_init(&env, envp);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	while (1)
		ft_client_socket(&env, &client_socket, sock);
	close(client_socket);
	close(sock);
	return (0);
}
