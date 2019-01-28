/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:00:40 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 15:27:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (str[i] - 'A' + c) % 26 + 'A';
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (str[i] - 'a' + c) % 26 + 'a';
		i++;
	}
	return (str);
}