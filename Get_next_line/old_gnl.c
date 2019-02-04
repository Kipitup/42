/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/02/04 19:09:49 by amartino         ###   ########.fr       */
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

int		ft_parse_line(char *str_total, char **line, int *ret)
{
	int		j;

	j = -1;
	while (str_total[++j])
	{
		if (str_total[j] == '\n')
		{
			if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
				return (0);
			*line = ft_memmove(*line, str_total, j);
			(*line)[j] = '\0';
			return (j);
		}
	}
	if (*ret == 0 && ((j = ft_strlen(str_total)) > 0))
	{
		if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
			return (0);
		*line = ft_memmove(*line, str_total, j);
		(*line)[j] = '\0';
		return (j - 1);
	}
	return (0);
}

char	*ft_read(int fd, char *str_total, int *ret)
{
	int				i;
	char			buff[BUFF_SIZE + 1];

	i = -1;
	while (*ret > 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((*ret = read(fd, &buff, BUFF_SIZE)) == -1)
			return (NULL);
		buff[BUFF_SIZE] = '\0';
		if (!str_total)
			str_total = ft_strdup(buff);
		else
			str_total = ft_strjoin(str_total, buff);
		while (str_total[++i])
		{
			if (str_total[i] == '\n')
				return (str_total);
		}
	}
	return (str_total);
}

int		get_next_line(const int fd, char **line)
{
	if (ft_checks(fd) == -1)
		return (-1);

	char static		*str_total;
	int				*ret;
	int				tmp;
	int				j;

	tmp = 1;
	ret = &tmp;
printf("\033[31;01m%d\033[00m\n", str_total);   //rouge
	if (str_total && *str_total)
	{
		if ((j = ft_parse_line(str_total, line, ret)) != 0)
			str_total = str_total + j + 1;
		if (j != 0)
			return (1);
	}
	if ((str_total = ft_read(fd, str_total, ret)) == NULL)
		return (-1);
	if ((j = ft_parse_line(str_total, line, ret)) != 0)
		str_total = str_total + j + 1;
	if (j != 0)
		return (1);
	return (0);
}




/*
printf("\033[32;01mOK\033[00m\n");  //vert
printf("\033[33;01m%d\033[00m\n", ret);  //jaune
printf("\033[31;01m%s\033[00m\n", str_total);   //rouge
printf("\033[34;01m%s\033[00m\n", buff);  //bleu
 *
 *pb : dernier appelle de get_line, quand pas de \n a la fin il ne faut pas
 avancer de str_total + j + 1. (pas le +1)

 si pendant le read, il y a un probleme et que -1 est retourné => PB
*/
