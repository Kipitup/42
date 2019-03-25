/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:47:54 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 14:58:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_u;

	i = -1;
	dst_u = (unsigned char*)dst;
	while (++i < n)
	{
		dst_u[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (dst_u + i + 1);
	}
	return (NULL);
}
