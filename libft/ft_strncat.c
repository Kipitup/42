/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:30:46 by amartino          #+#    #+#             */
/*   Updated: 2018/12/14 14:29:02 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		count;

	i = -1;
	count = ft_strlen(s1);
	while (++i < n && *s2)
		s1[count++] = *(s2++);
	s1[count] = '\0';
	return (s1);
}
