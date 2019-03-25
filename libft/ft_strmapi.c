/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:21:38 by amartino          #+#    #+#             */
/*   Updated: 2018/12/17 12:20:11 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	i = -1;
	if (!s)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[++i])
		tmp[i] = f(i, s[i]);
	tmp[i] = '\0';
	return (tmp);
}
