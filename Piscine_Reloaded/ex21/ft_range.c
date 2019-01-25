/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:45 by amartino          #+#    #+#             */
/*   Updated: 2018/11/09 14:10:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		range;
	int		i;
	int		*tab;

	i = 0;
	range = max - min;
	if (min >= max)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * range)))
		return (NULL);
	while (i < range)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
