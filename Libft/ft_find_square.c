/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:28:50 by amartino          #+#    #+#             */
/*   Updated: 2018/02/26 09:09:47 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_find_square(float nb)
{
	int		len;
	int		limit;
	float	guess;

	guess = 1;
	len = ft_intlen(nb) - 1;
	while (--len > 0)
		guess *= 10;
	limit = guess + 9;
	while (--limit > 0)
		guess = ((nb / guess) + guess) / 2;
	return (guess);
}
