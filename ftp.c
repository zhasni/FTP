/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:31:33 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/02 21:22:06 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void		ft_get_env(t_env *env, char **envp)
{
	int		i;
	int		lentab;

	i = 0;
	lentab = ft_tablen(envp);
	if (!(env->bkp = malloc(sizeof(char *) * lentab)))
		return ;
	while (envp[i])
	{
		env->bkp[i] = ft_strdup(envp[i]);
		i++;
	}
	env->bkp[i] = NULL;
	env->oldpwd = ft_get_line_env(env, "OLDPWD");
	return ;
}

int			ft_replace_line_env(t_env *env, char *key, char *newpath)
{
	int		index;
	int		i;
	char	*tmp;

	index = 0;
	while (env->bkp[index])
	{
		i = 0;
		while (env->bkp[i] && key[i] && key[i] == env->bkp[index][i])
			i++;
		if (env->bkp[index][i] == '=')
		{
			tmp = ft_my_join(key, "=");
			env->bkp[index] = ft_my_join(tmp, newpath);
			return (1);
		}
		index++;
	}
	return (0);
}

char		*ft_get_line_env(t_env *env, char *key)
{
	int		index;
	int		i;

	index = 0;
	while (env->bkp[index])
	{
		i = 0;
		while (env->bkp[i] && key[i] && key[i] == env->bkp[index][i])
			i++;
		if (env->bkp[index][i] == '=')
			return (&env->bkp[index][i + 1]);
		index++;
	}
	return (NULL);
}
