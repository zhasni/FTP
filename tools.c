/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:11:32 by zhasni            #+#    #+#             */
/*   Updated: 2015/04/02 22:18:18 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char		*ft_tolowerstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_my_join(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (!tmp)
		return (NULL);
	while (s1[j] && j <= len && i <= len)
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j] && j <= len && i <= len)
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_my_join2(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (!tmp)
		return (NULL);
	while (s1[j] && j <= len && i <= len)
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j] && j <= len && i <= len)
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char		*ft_strtri(char const *s)
{
	int		i;
	int		j;
	int		len;
	int		size;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	size = len - i;
	if (size < 0)
		size = 0;
	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	while (i <= len)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}
