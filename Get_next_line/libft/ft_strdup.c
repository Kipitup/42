/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:46:23 by amartino          #+#    #+#             */
/*   Updated: 2019/03/16 21:26:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	i = -1;
	size = ft_strlen(src);
	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < size)
		tmp[i] = src[i];
	tmp[i] = '\0';
	return (tmp);
}
