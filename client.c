/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 20:53:39 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 22:50:33 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void			ft_receive_serveur(int server_socket, int flag)
{
	int			res;
	int			len;
	int			i;
	char		*tmp;
	char		*txt;

	txt = malloc(1);
	tmp = malloc(1024);
	res = recv(server_socket, &len, 4, 0);
	if (res < 0)
		return ;
	i = 0;
	while (i < len)
	{
		res = recv(server_socket, tmp, 1023, 0);
		if (res < 0)
			break ;
		tmp[res] = '\0';
		txt = ft_check_get(tmp, txt, &flag);
		ft_bzero(tmp, ft_strlen(tmp));
		i += res;
	}
	if (flag == 1)
		ft_getfile(txt);
	ft_putstr_color_fd("\033[0;35m", "[ client ] : ", 1);
}

void			ft_loop_client(int server_socket)
{
	int			r;
	char		buf[1024];
	int			flag;
	int			len;
	char		*str;

	ft_putstr_color_fd("\033[0;35m", "[ client ] : ", 1);
	while ((r = read(0, buf, 1023)) > 0)
	{
		flag = 0;
		buf[r] = '\0';
		ft_check_quit(buf, server_socket);
		str = buf;
		if (ft_prompt_bis(server_socket, str) > 0)
			continue ;
		len = ft_strlen(buf);
		write(server_socket, buf, ft_strlen(buf));
		ft_bzero(buf, ft_strlen(buf));
		ft_receive_serveur(server_socket, flag);
	}
}

int				main(int ac, char **av)
{
	int			port;
	int			server_socket;

	signal(SIGINT, handle_signal);
	if (ac != 3)
		usage(av[0]);
	if (ft_strcmp(av[1], "localhost") == 0)
		av[1] = "127.0.0.1";
	port = ft_atoi(av[2]);
	server_socket = create_client(av[1], port);
	ft_loop_client(server_socket);
	close(server_socket);
	return (0);
}
