/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:44:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 14:07:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char *s)
{
	if (s != NULL)
		while (*s)
			*(s++) = 0;
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			while (++i < n)
				dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*exact;

	if (!(exact = (char*)malloc(sizeof(char) * (++size))))
		return (NULL);
	while (size > 0)
		exact[--size] = '\0';
	exact[0] = '\0';
	return (exact);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	size1;
	int	size2;
	int	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char*)ft_strnew(size1 + size2)))
		return (NULL);
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i = -1;
	while (++i < size2)
		str[i + size1] = s2[i];
	str[size1 + size2] = '\0';
	return (str);
}
