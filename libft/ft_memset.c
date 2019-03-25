/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:21:04 by amartino          #+#    #+#             */
/*   Updated: 2018/12/14 17:35:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned long	i;

	i = 0;
	while (i < len)
		((unsigned char*)str)[i++] = (unsigned char)c;
	return (str);
}
