/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:54:54 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 14:54:25 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_u;

	s_u = (unsigned char*)s;
	while (n > 0)
	{
		if (*s_u == (unsigned char)c)
			return (s_u);
		s_u++;
		n--;
	}
	return (NULL);
}
