/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:15:16 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/21 22:19:48 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int			ft_check_cd(char *line, t_env *env)
{
	char	**cdtab;

	ft_bzero(env->tmp, ft_strlen(env->tmp));
	line = ft_epur_str(line);
	cdtab = ft_strsplit(line, ' ');
	if (ft_strcmp(line, "cd") == 0)
		ft_cd_home(env);
	else if (cdtab[1][0] == '-')
		ft_cd_minus(env, line);
	else if (cdtab[1][0] == '~')
		ft_cd_tilde(env, cdtab);
	else if (cdtab[1][0] == '/')
		ft_cd_slash(env, cdtab[1]);
	else if (cdtab[0] && cdtab[1])
		ft_cd(line, env);
	return (0);
}

int			ft_check_build(char *line, t_env *env)
{
	char	**cmd;
	char	*minmaj;
	int		i;

	i = 0;
	cmd = ft_strsplit(line, ' ');
	if (!cmd || !cmd[0])
		return (-1);
	while (cmd[i++])
		cmd[i] = ft_strtri(cmd[i]);
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_check_cd(line, env));
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (ft_setenv(line, env));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (ft_unsetenv(line, env));
	minmaj = ft_tolowerstr(cmd[0]);
	if (ft_strcmp(minmaj, "env") == 0)
		return (ft_env(env, cmd));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd[1]);
	else if (ft_strcmp(cmd[0], "get") == 0)
		return (ft_get(env, cmd[1]));
	return (-1);
}

int			ft_check_slash(t_env *env, char *line)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = "";
	tmp2 = NULL;
	if (line[0] == '/')
	{
		env->arg = ft_strsplit(line, ' ');
		while (env->arg[i])
		{
			env->arg[i] = ft_strtri(env->arg[i]);
			i++;
		}
		return (1);
	}
	else if ((line[0] == '.' && line[1] == '/'))
	{
		line = ft_my_join(tmp, line + 1);
		line = ft_my_join(getcwd(tmp2, MAXPATHLEN), line);
		env->arg = ft_strsplit(line, ' ');
		return (1);
	}
	return (0);
}

char		*ft_check_path(t_env *env, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	line = ft_strtri(line);
	while (env->path[i])
	{
		tmp = ft_my_join(env->path[i], line);
		env->arg = ft_strsplit(tmp, ' ');
		while (env->arg[j])
		{
			env->arg[j] = ft_strtri(env->arg[j]);
			j++;
		}
		if (access(env->arg[0], 0) == F_OK)
			return (env->arg[0]);
		i++;
	}
	return (env->arg[i]);
}

char		*ft_check_filename(char *txt, int *i)
{
	char	tmp[1024];
	char	*tmp2;
	int		j;

	j = 0;
	tmp2 = NULL;
	while (txt[*i])
	{
		if (txt[*i] == ' ')
			break ;
		*i = *i + 1;
	}
	*i = *i + 1;
	while (txt[*i] != '\n')
	{
		tmp[j] = txt[*i];
		*i = *i + 1;
		j++;
	}
	*i = *i + 1;
	tmp[j] = '\0';
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	tmp2 = ft_my_join(tmp2, "/");
	tmp2 = ft_my_join(tmp2, tmp);
	return (tmp2);
}
