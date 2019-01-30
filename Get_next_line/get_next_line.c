/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/01/30 22:25:38 by amartino         ###   ########.fr       */
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

char	*ft_get_line(char *str_total, char **line, int j)
{
	if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
		return (0);
	*line = ft_memmove(*line, str_total, j);
	(*line)[j] = '\0';
	str_total = str_total + j + 1;
	return (str_total);
}

int		ft_parse_line(char *str_total)
{
	int		j;

	j = -1;
	while (str_total[++j])
	{
		if (str_total[j] == '\n')
			return (j);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	if (ft_checks(fd) == -1)
		return (-1);

	char			buff[BUFF_SIZE + 1];
	char static		*str_total;
	int				ret;
	int				i;
	int				j;

	i = 0;
	if (str_total && *str_total)
	{
		if ((j = ft_parse_line(str_total)) != 0)
		{
			str_total = ft_get_line(str_total, line, j);
			return (1);
		}
		else if ((j = ft_strlen(str_total)) > 0)
		{
			str_total = ft_get_line(str_total, line, j);
			return (1);
		}
	}
	while ((ret = read(fd, &buff, BUFF_SIZE)))
	{
printf("\033[32;01m%zu\033[00m\n", ft_strlen(buff));  //vert
		buff[BUFF_SIZE] = '\0';
printf("\033[32;01m%s\033[00m\n", buff);  //vert
		if (!str_total)
			str_total = ft_strdup(buff);
		else
			str_total = ft_strjoin(str_total, buff);
		ft_strclr(buff);
		while (str_total[i])
		{
			if ((j = ft_parse_line(str_total)) != 0)
			{
				str_total = ft_get_line(str_total, line, j);
				return (1);
			}
			i++;
		}
	}
	if (str_total && *str_total && ret == 0)
	{
		buff[BUFF_SIZE] = '\0';
		str_total = ft_strjoin(str_total, buff);
		ft_strclr(buff);
		if ((j = ft_parse_line(str_total)) != 0)
		{
			str_total = ft_get_line(str_total, line, j);
			return (1);
		}
		else if ((j = ft_strlen(str_total)) > 0)
		{
			str_total = ft_get_line(str_total, line, j);
			return (1);
		}
	}
	return (0);
}

/* je pense que les fichier qui n'ont pas de \n de se print pas sur la derniere ligne
 * alors qu'il le faut 
 *
 *
printf("\033[32;01m%s\033[00m\n", str_total);  //vert
printf("\033[33;01m%d\033[00m\n", ret);  //jaune
printf("\033[31;01m%s\033[00m\n", str_total);   //rouge
printf("\033[34;01m%s\033[00m\n", buff);  //bleu
 *
 *
 * verifier si j'ai deja read quelque chose
 * if parse then get_line
 *
 * si rien de nouveau read again, je strjoin mon buffer vers str_total
 * if parse then get_line
 *
 * quand j'ai fini de read
 * if parse then get_line
*/
