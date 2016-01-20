/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 22:12:15 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/21 22:25:58 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int			ft_str_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '.')
			return (1);
		i++;
	}
	return (0);
}

void		ft_cd_slash(t_env *env, char *arg)
{
	char	*tmp2;

	tmp2 = NULL;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (access(arg, 0) == F_OK && ft_strlen(arg) >= 58 && chdir(arg) == 0)
	{
		if (ft_replace_line_env(env, "PWD", arg) == 0)
			ft_add_line(env, "PWD", arg);
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		env->oldpwd = tmp2;
	}
	else
		ft_error_cd(arg, 2, env);
}

void		ft_cd_tilde_bis(t_env *env, char *newpath, char *tmp2)
{
	if (ft_replace_line_env(env, "PWD", newpath) == 0)
		ft_add_line(env, "PWD", newpath);
	if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
		ft_add_line(env, "OLDPWD", tmp2);
	env->oldpwd = tmp2;
}

void		ft_cd_tilde(t_env *env, char **cdtab)
{
	char	*newpath;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = ft_my_join(env->home, "");
	newpath = ft_my_join(tmp, cdtab[1] + 1);
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (access(newpath, 0) == F_OK && ft_strlen(newpath) >= 58 &&
		chdir(newpath) == 0)
		ft_cd_tilde_bis(env, newpath, tmp2);
	else
	{
		tmp = ft_my_join(tmp, "/");
		tmp = ft_my_join(tmp, cdtab[1] + 1);
		if (access(tmp, 0) == F_OK && ft_strlen(tmp) >= 58)
			ft_error_cd(cdtab[1], 2, env);
		else
			ft_error_cd(cdtab[1], 1, env);
	}
}

void		ft_cd_home(t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = env->pwd;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (chdir(tmp) == 0 && ft_strlen(tmp) >= 58)
	{
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		if (ft_replace_line_env(env, "PWD", tmp) == 0)
			ft_add_line(env, "PWD", getcwd(tmp2, MAXPATHLEN));
		env->oldpwd = tmp2;
	}
}
