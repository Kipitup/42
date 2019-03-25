/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:57:11 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 15:24:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *str, char c)
{
	size_t		count;

	count = 0;
	while (*str)
	{
		if (*str != c)
			count++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (count);
}
