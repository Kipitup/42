/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:47:01 by amartino          #+#    #+#             */
/*   Updated: 2018/12/14 12:18:48 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src <= dst)
	{
		while (len > 0)
		{
			((char*)dst)[len - 1] = ((char*)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
			((char*)dst)[i] = ((char*)src)[i];
	}
	return (dst);
}
