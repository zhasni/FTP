/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:38:23 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/03 17:40:12 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_epur_str(char *src)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!src || !(tmp = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		if ((src[i] == ' ' || src[i] == '	') && src[i])
		{
			i++;
			if ((tmp[j - 1] > 32 && tmp[j - 1] < 127) && (src[i] > 32 && src[i]
						< 127))
				tmp[j++] = ' ';
			continue ;
		}
		if (src[i] > 32 && src[i] < 127)
			tmp[j++] = src[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
