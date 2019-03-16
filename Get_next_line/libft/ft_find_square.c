/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:28:50 by amartino          #+#    #+#             */
/*   Updated: 2019/02/27 14:56:05 by tvitoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_find_square(float nb)
{
	int		len;
	int		limit;
	float	guess;

	guess = 1;
	limit = 20;
	len = ft_intlen(nb) - 1;
	while (--len > 0)
		guess *= 10;
	while (--limit > 0)
		guess = ((nb / guess) + guess) / 2;
	return (guess);
}
