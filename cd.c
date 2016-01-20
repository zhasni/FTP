/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:12:56 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/21 22:17:29 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void		ft_cd(char *line, t_env *env)
{
	char	**cdtab;
	char	*newpath;
	char	*tmp;

	tmp = NULL;
	cdtab = ft_strsplit(line, ' ');
	tmp = getcwd(tmp, MAXPATHLEN);
	newpath = ft_my_join(tmp, "/");
	newpath = ft_my_join(newpath, cdtab[1]);
	if (access(newpath, 0) == F_OK && ft_strlen(newpath) >= 58
		&& chdir(newpath) == 0)
		ft_cd_ter(tmp, newpath, env);
	else
		ft_cd_bis(tmp, cdtab, env);
}

void		ft_cd_ter(char *tmp, char *newpath, t_env *env)
{
	newpath = getcwd(newpath, MAXPATHLEN);
	if (ft_strlen(newpath) < (size_t)env->len)
	{
		ft_cd_home(env);
		return ;
	}
	if (ft_replace_line_env(env, "OLDPWD", tmp) == 0)
		ft_add_line(env, "OLDPWD", tmp);
	if (ft_replace_line_env(env, "PWD", getcwd(tmp, MAXPATHLEN)) == 0)
		ft_add_line(env, "PWD", getcwd(tmp, MAXPATHLEN));
	env->oldpwd = tmp;
}

void		ft_cd_bis(char *tmp, char **cdtab, t_env *env)
{
	tmp = ft_my_join(tmp, "/");
	tmp = ft_my_join(tmp, cdtab[1]);
	if (access(tmp, 0) == R_OK && access(tmp, 0) == F_OK)
		ft_error_cd(cdtab[1], 2, env);
	else if (access(tmp, 0) != R_OK && access(tmp, 0) == F_OK)
		ft_error_cd(cdtab[1], 3, env);
	else
		ft_error_cd(cdtab[1], 1, env);
}

void		ft_cd_minus_bis(char *tmp, char *tmp2, char **cdtab, t_env *env)
{
	(void)tmp;
	if (access(tmp2, 0) == F_OK && ft_strlen(tmp2) >= 58)
		ft_error_cd(cdtab[1], 2, env);
	else
		ft_error_cd(cdtab[1], 1, env);
}

void		ft_cd_minus(t_env *env, char *line)
{
	char	*tmp;
	char	*tmp2;
	char	**cdtab;

	tmp2 = NULL;
	cdtab = ft_strsplit(line, ' ');
	if (!cdtab)
		return ;
	tmp = env->oldpwd;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (!cdtab[2] && chdir(tmp) == 0 && ft_strlen(tmp) >= 58)
	{
		if (ft_replace_line_env(env, "PWD", tmp) == 0)
			ft_add_line(env, "PWD", tmp);
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		env->oldpwd = tmp2;
	}
	else
		ft_cd_minus_bis(tmp, tmp2, cdtab, env);
}
