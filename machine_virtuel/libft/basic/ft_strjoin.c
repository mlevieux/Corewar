/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlancien <vlancien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:35:42 by vlancien          #+#    #+#             */
/*   Updated: 2016/10/22 03:06:01 by vlancien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*res;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	length = 0;
	while (s1[length])
	{
		res[length] = s1[length];
		length++;
	}
	i = 0;
	while (s2[i])
	{
		res[length + i] = s2[i];
		i++;
	}
	res[length + i] = '\0';
	return (res);
}
