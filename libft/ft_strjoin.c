/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:34:29 by amartino          #+#    #+#             */
/*   Updated: 2018/12/17 14:28:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*s_concat;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s_concat = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
		s_concat[i++] = *s1++;
	while (*s2)
		s_concat[i++] = *s2++;
	s_concat[i] = '\0';
	return (s_concat);
}
