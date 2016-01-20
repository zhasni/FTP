/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:29:23 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/02 21:21:08 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	ft_error(char *line, t_env *env)
{
	char	**tmp;

	if (ft_isprint(line[0]))
	{
		tmp = ft_strsplit(line, ' ');
		ft_putstr_color_fd("\033[0;35m", "ft_minishell1 : command not found: "
			, env->client_socket);
		ft_putstr_color_fd("\033[0;36m", tmp[0], env->client_socket);
		ft_putstr_fd("\n", env->client_socket);
		free(tmp);
	}
}

void	ft_error_setenv(int n, t_env *env)
{
	if (n == 1)
	{
		env->tmp = ft_my_join(env->tmp, "ERROR ");
		env->tmp = ft_my_join(env->tmp,
			"\033[0;31m setenv : Too many arguments \033[0m\n");
	}
	else if (n == 2)
	{
		env->tmp = ft_my_join(env->tmp, "ERROR ");
		env->tmp = ft_my_join(env->tmp,
			"\033[0;31m setenv: PATH: Permission denied \033[0m\n");
	}
	else if (n == 0)
	{
		env->tmp = ft_my_join(env->tmp, "ERROR ");
		env->tmp = ft_my_join(env->tmp,
			"\033[0;31m unsetenv : Too few arguments \033[0m\n");
	}
	else
	{
		env->tmp = ft_my_join(env->tmp, "ERROR ");
		env->tmp = ft_my_join(env->tmp, "\033[0;31m unsetenv : Too many ");
		env->tmp = ft_my_join(env->tmp, "arguments or Permission denied ");
		env->tmp = ft_my_join(env->tmp, "\033[0m\n");
	}
}

void	ft_error_cd_ter(char *line, int n, t_env *env)
{
	char	**tmp;

	if (n == 3)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			env->tmp = ft_my_join(env->tmp, "ERROR ");
			env->tmp = ft_my_join(env->tmp,
				"\033[0;31m cd: not a directory: \033[0;31m");
			env->tmp = ft_my_join(env->tmp, tmp[0]);
			env->tmp = ft_my_join(env->tmp, "\033[0m\n");
			free(tmp);
		}
	}
}

void	ft_error_cd_bis(char *line, int n, t_env *env)
{
	char	**tmp;

	if (n == 2)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			env->tmp = ft_my_join(env->tmp, "ERROR ");
			env->tmp = ft_my_join(env->tmp,
				"\033[0;31m cd: permission denied2: \033[0;31m");
			env->tmp = ft_my_join(env->tmp, tmp[0]);
			env->tmp = ft_my_join(env->tmp, "\033[0m\n");
			free(tmp);
		}
	}
}

void	ft_error_cd(char *line, int n, t_env *env)
{
	char	**tmp;

	if (n == 1)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			env->tmp = ft_my_join(env->tmp, "ERROR ");
			env->tmp = ft_my_join(env->tmp,
				"\033[0;31m cd: no such file or directory: \033[0;31m");
			env->tmp = ft_my_join(env->tmp, tmp[0]);
			env->tmp = ft_my_join(env->tmp, "\033[0m\n");
			free(tmp);
		}
	}
	else if (n == 2)
		ft_error_cd_bis(line, n, env);
	else
		ft_error_cd_ter(line, n, env);
}
