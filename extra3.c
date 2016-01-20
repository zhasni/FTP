/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 22:31:30 by zhasni            #+#    #+#             */
/*   Updated: 2015/05/12 18:00:18 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char			**ft_check_tab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	if (i > 1)
	{
		while (tab[1][i])
		{
			if (tab[1][i] == '\n')
				tab[1][i] = '\0';
			i++;
		}
	}
	return (tab);
}

void			ft_check_quit(char *buf, int server_socket)
{
	if (ft_strcmp(buf, "quit\n") == 0)
	{
		close(server_socket);
		exit(0);
	}
}

int				ft_check_put(char *buf, int server_socket)
{
	char		**tab;
	char		*tmp;
	int			len;

	tab = ft_strsplit(buf, ' ');
	tab = ft_check_tab(tab);
	if (ft_strcmp(tab[0], "put") == 0 && tab[1])
	{
		tmp = ft_put(tab[1]);
		if (!tmp)
			printf("ERROR\n");
		else
		{
			len = ft_strlen(tmp);
			write(server_socket, tmp, len);
			printf("SUCCESS\n");
		}
		return (1);
	}
	return (0);
}

char			*ft_put(char *str)
{
	int			ret;
	int			fd;
	char		buf[1024];
	char		*tmp;

	tmp = malloc(1);
	tmp[0] = '\0';
	fd = open(str, O_RDONLY, 0666);
	if (fd < 0)
	{
		printf("OPEN ERROR\n");
		return (NULL);
	}
	else
	{
		while ((ret = read(fd, buf, 1023)) > 0)
		{
			buf[ret] = '\0';
			tmp = ft_my_join(tmp, buf);
		}
		tmp = ft_my_join("\n", tmp);
		tmp = ft_my_join(str, tmp);
		tmp = ft_my_join("putfile ", tmp);
	}
	return (tmp);
}

int				ft_prompt_bis(int server_socket, char *str)
{
	if (ft_check_put(str, server_socket) == 1)
	{
		ft_putstr_color_fd("\033[0;35m", "[ client ] : ", 1);
		return (1);
	}
	else if (ft_strcmp(str, "\n") == 0)
	{
		ft_putstr_color_fd("\033[0;35m", "[ client ] : ", 1);
		return (2);
	}
	return (0);
}
