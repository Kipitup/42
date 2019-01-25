/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:43:09 by amartino          #+#    #+#             */
/*   Updated: 2018/11/09 12:17:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (i < ft_strlen(src))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
