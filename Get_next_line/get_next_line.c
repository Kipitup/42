/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/01/27 20:22:03 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_checks(const int fd)
{
	if (fd < 0)
		return (-1);
	if (fcntl(fd, F_GETFD) == -1)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	if (ft_checks(fd) == -1)
		return (-1);

	char		buff[BUFF_SIZE + 1];
	char		*s;
	char static	*str_total;
	int			i;
	int			tmp;
	int			j;

	i = 0;  //i et j se réinitialise a chaque appel de gnl. 
	j = 0;	//je dois garder un trace de ou j'en etais
	while ((tmp = read(fd, &buff, BUFF_SIZE)))
	{
		buff[BUFF_SIZE] = '\0';
		if (!s)
		{
			str_total = ft_strdup(buff);
			s = ft_strdup(buff);
		}
		else
		{
			str_total = ft_strjoin(str_total, buff);
		}
		ft_strclr(buff);
		while (str_total[j])
		{
			if (str_total[j] == '\n')
			{
				printf("\033[34;01m%s\033[00m\n", str_total);
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
	if (i < j)
	{
		if (!(*line = (char*)malloc(sizeof(char) * (j - i + 1))))
			return (0);
		*line = ft_memmove(*line, &(str_total[i]), (j - i));
		(*line)[j - i] = '\0';
		i = j;
		return (1);
	}
	if (tmp == 0 || tmp == -1)
		return (tmp);
	return (1);
}

/* verifier si j'ai deja read quelque chose 
parcourir a la recherche de \n
		quand je tombe sur un \n je memmove sur ma *line puis j'avance sur str_total

si rien de nouveau read again
parcourir a la recherche de \n
		quand je tombe sur un \n je memmove sur ma *line puis j'avance sur str_total

quand j'ai fini de read, parcourir la chaine a la recherche de \n 
		quand je tombe sur un \n je memmove sur ma *line puis j'avance sur str_total
*/
