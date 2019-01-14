/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:13 by amartino          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:13 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_display_line(char *s, int j)
{
	write(1, s, j);
}

int		ft_read(int file_descriptor)
{
	char		buff[2];
	static char	*str_total;
	int		buffer;
	int		i;
	int		j;
	int		secure;

	secure = 0;
	i = 0;
	j = 0;
	buffer = 1 * sizeof(char);
	secure = read(file_descriptor, &buff, buffer);
	buff[1] = '\0';
	str_total = buff;
	if (secure < 0)
		return 0;
	while (secure == buffer)
	{
		str_total = ft_strjoin(str_total, buff);
	//	printf("      %s\n", str_total);
	//	printf("......%d\n", j);
		while (str_total[j])
		{
			if (str_total[j] == '\n')
			{
				//printf("\ni = %d et j = %d\n", i, j);
				ft_display_line(&(str_total[i]), (j - i));
				i = j;
				//printf("\ni = %d et j = %d\n", i, j);
			}
			j++;
		}
		secure = read(file_descriptor, &buff, buffer);
		buff[1] = '\0';
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	file_descriptor;
	int	i;

	if (ac < 2)
		return 0;
	else if (ac > 2)
		return 0;
	else
	{
		i = 0;
		if (!(file_descriptor = open(av[1], O_RDONLY)))
			return (0);
		if (!ft_read(file_descriptor))
			return (0);
		if (-1 == close(file_descriptor))
			return 0;
	}
	return (0);
}
