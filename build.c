/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:03:27 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/21 22:11:15 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int			ft_exit(char *s)
{
	if (!s)
		exit (0);
	exit(ft_atoi(s));
	return (0);
}

int			ft_env(t_env *env, char **cmd)
{
	int		i;

	i = 0;
	(void)env;
	if (cmd[0] && cmd[1])
	{
		ft_error(cmd[1], env);
		return (0);
	}
	ft_bzero(env->tmp, ft_strlen(env->tmp));
	while (env->bkp[i])
	{
		env->tmp = ft_my_join(env->tmp, "\033[0;30m MY ENV = \033[0;33m");
		env->tmp = ft_my_join(env->tmp, env->bkp[i]);
		env->tmp = ft_my_join(env->tmp, "\n\033[0m");
		i++;
	}
	return (0);
}

void		ft_setenv_bis(char **tmp, t_env *env, int ret, int len)
{
	if (ret == 0 && len <= 3)
		ft_add_line(env, tmp[1], tmp[2]);
	else
		ft_error_setenv(1, env);
}

int			ft_setenv(char *line, t_env *env)
{
	char	**tmp;
	int		ret;
	int		len;

	ret = 0;
	tmp = ft_strsplit(line, ' ');
	ft_bzero(env->tmp, ft_strlen(env->tmp));
	if (!tmp[1])
	{
		ft_env(env, tmp);
		ft_bzero(env->tmp, ft_strlen(env->tmp));
		return (0);
	}
	len = ft_tablen(tmp);
	if (!tmp[2])
		tmp[2] = "";
	ret = ft_check_line_env(env, tmp[1]);
	if (ft_strcmp(tmp[1], "PATH") == 0)
		ft_error_setenv(2, env);
	else if (ret > 0 && len <= 3)
		ft_replace_line_env(env, tmp[1], tmp[2]);
	ft_setenv_bis(tmp, env, ret, len);
	return (0);
}

int			ft_unsetenv(char *line, t_env *env)
{
	int		ret;
	char	**tmp;

	ft_bzero(env->tmp, ft_strlen(env->tmp));
	tmp = ft_strsplit(line, ' ');
	if (!tmp || !tmp[0] || !tmp[1])
	{
		ft_error_setenv(0, env);
		return (0);
	}
	ret = ft_check_line_env(env, tmp[1]);
	if (ret > 0)
	{
		ft_delete_line(env, tmp[1]);
		ft_resize_tab(env);
	}
	else
		ft_error_setenv(4, env);
	return (0);
}
