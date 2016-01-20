/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 22:29:25 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 17:04:25 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void						usage(char *str)
{
	printf("Usage : %s <addr> <port>\n", str);
	exit(-1);
}

void						handle_signal(int signo)
{
	signo++;
	ft_putstr_color_fd("\033[0;34m", "\n[ client ] : ", 1);
}

int							create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect Error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

void						ft_getfile(char *txt)
{
	int						fd;
	int						i;
	char					*tmp2;

	i = 0;
	tmp2 = ft_check_filename(txt, &i);
	fd = open(tmp2, S_IRWXU | O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
	{
		printf("Error fd\n");
		exit(-1);
	}
	printf("SUCCESS\n");
	write(fd, &txt[i], ft_strlen(&txt[i]));
	ft_bzero(txt, ft_strlen(txt));
}

char						*ft_check_get(char *tmp, char *txt, int *flag)
{
	if (ft_strncmp(tmp, "SUCCESS\ngetfile", 15) == 0)
		*flag = 1;
	if (*flag == 1)
		txt = ft_my_join(txt, tmp);
	if (*flag == 0)
		printf("%s", tmp);
	return (txt);
}
