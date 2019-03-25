/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:39:43 by amartino          #+#    #+#             */
/*   Updated: 2018/12/17 14:53:56 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	tmp;
	int		sign;
	int		counter;
	char	*str;

	tmp = n;
	sign = (n < 0) ? -1 : 1;
	counter = (n < 0) ? 1 : 0;
	if (tmp < 0)
		tmp *= -1;
	if (n == 0)
		counter++;
	while (n != 0 && counter++ >= 0)
		n /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	str[counter] = '\0';
	while (--counter >= 0)
	{
		str[counter] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
