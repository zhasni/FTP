/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:29:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/03/26 20:29:28 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int			ft_check_line_env(t_env *env, char *key)
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
			return (index);
		index++;
	}
	return (0);
}

void		ft_add_line(t_env *env, char *key, char *arg)
{
	int		len;
	int		i;
	char	**new_env;

	i = 0;
	len = ft_tablen(env->bkp);
	if (!(new_env = (char **)malloc(sizeof(char *) * (len + 1))))
		return ;
	while (i < len)
	{
		new_env[i] = env->bkp[i];
		i++;
	}
	new_env[i] = ft_my_join(key, "=");
	new_env[i] = ft_my_join(new_env[i], arg);
	new_env[++i] = NULL;
	env->bkp = new_env;
}

void		ft_delete_line(t_env *env, char *key)
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
			env->bkp[index] = "";
		index++;
	}
}

void		ft_resize_tab(t_env *env)
{
	int		i;
	int		j;
	int		len;
	char	**sized_env;

	i = 0;
	j = 0;
	len = ft_tablen(env->bkp);
	if (!(sized_env = (char **)malloc(sizeof(char *) * (len))))
		return ;
	while (i < len)
	{
		if (ft_strcmp(env->bkp[i], "") == 0)
			i++;
		else
		{
			sized_env[j] = env->bkp[i];
			j++;
			i++;
		}
	}
	sized_env[--i] = NULL;
	env->bkp = sized_env;
}
