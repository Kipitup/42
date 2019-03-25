/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:11:04 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 09:17:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		j;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		j = 0;
		while (haystack[j] == needle[j] && haystack[j] && needle[j])
			j++;
		if (!needle[j])
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
