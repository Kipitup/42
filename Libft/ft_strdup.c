/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:46:23 by amartino          #+#    #+#             */
/*   Updated: 2018/11/14 12:53:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*tmp;

	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (++i < ft_strlen(src))
		tmp[i] = src[i];
	tmp[i] = '\0';
	return (tmp);
}
