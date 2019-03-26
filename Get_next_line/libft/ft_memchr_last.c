/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:41:26 by amartino          #+#    #+#             */
/*   Updated: 2019/03/26 15:42:03 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr_last(const void *s, int c, size_t n)
{
	unsigned char	*s_u;
	unsigned char	*tmp;

	s_u = (unsigned char*)s;
	tmp = NULL;
	while (n > 0)
	{
		if (*s_u == (unsigned char)c)
			tmp = s_u;
		s_u++;
		n--;
	}
	return (tmp ? tmp : NULL);
}
