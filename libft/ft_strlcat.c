/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:58:01 by amartino          #+#    #+#             */
/*   Updated: 2018/12/14 17:24:24 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			dst_base_size;
	unsigned int	i_max;
	size_t			src_base_size;

	i = -1;
	dst_base_size = ft_strlen(dst);
	src_base_size = ft_strlen(src);
	if (size < dst_base_size + 1)
		return (src_base_size + size);
	i_max = size - 1 - dst_base_size;
	while (++i < i_max && *src)
		dst[dst_base_size + i] = *(src++);
	dst[dst_base_size + i] = '\0';
	return (dst_base_size + src_base_size);
}
