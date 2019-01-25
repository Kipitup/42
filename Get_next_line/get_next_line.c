/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:13 by amartino          #+#    #+#             */
/*   Updated: 2019/01/25 15:49:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str_total;
	int			i;
	int			tmp;
	int			j;

	i = 0;
	j = 0;
	if (!(str_total = (char*)malloc(sizeof(char) * 1)))
		return (0);
	*str_total = '\0';
	while ((tmp = read(fd, &buff, BUFF_SIZE)))
	{
		buff[BUFF_SIZE] = '\0';
		str_total = ft_strjoin(str_total, buff);
		ft_strclr(buff);
		while (str_total[j])
		{
			if (str_total[j] == '\n')
			{
				if (!(*line = (char*)malloc(sizeof(char) * (j - i + 1))))
					return (0);
				*line = ft_memmove(*line, &(str_total[i]), (j - i));
				(*line)[j - i] = '\0';
				i = j;
				return (1);
			}
			j++;
		}
	}
	if (tmp == 0)
		return (0);
	return (1);
}
/*
int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line;
	if (ac < 2)
		return 0;
	else if (ac > 2)
		return 0;
	else
	{
		i = 0;
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		while ((i = get_next_line(fd, &line)))
		{
			printf("%s", line);
			printf("\n");
		}
		if (-1 == close(fd))
			return 0;
	}
	return (0);
}
//printf("\033[34;01m%s\033[00m\n", line);
*/
