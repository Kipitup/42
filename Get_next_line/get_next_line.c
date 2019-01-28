/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/01/28 19:17:09 by amartino         ###   ########.fr       */
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

char	*ft_get_line(char *str_total, char **line, int i)
{
	if (!(*line = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	*line = ft_memmove(*line, str_total, i);
	(*line)[i] = '\0';
	str_total = str_total + i;
		printf("\033[32;01m%s\033[00m\n", str_total);  //vert
	return (str_total);
}

int		ft_parse_line(char *str_total)
{
	int		i;

	i = -1;
	while (str_total[++i])
	{
		if (str_total[i] == '\n')
		{
		//	str_total = ft_get_line(str_total, line, i);
			return (i);
		}
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

	i = 0;
	printf("\033[31;01m%s\033[00m\n", str_total);   //rouge
//	if (str_total && *str_total)
//	{
//		if (ft_parse_line(str_total, line))
//			return (1);
//	}
	while ((ret = read(fd, &buff, BUFF_SIZE)))
	{
		buff[BUFF_SIZE] = '\0';
		if (!str_total)
			str_total = ft_strdup(buff);
		else
			str_total = ft_strjoin(str_total, buff);
		ft_strclr(buff);
		printf("\033[33;01mSalut\033[00m\n");  //jaune
		while (str_total[i])  //semblerai que le i s'incremente mal en tout cas on ne rentre pas dans if
		{
			printf("\033[34;01mSalut\033[00m\n");  //bleu
			if ((i = ft_parse_line(str_total)) != 0)
			{
				str_total = ft_get_line(str_total, line, i);
				return (1);
			}
			i++;
		}
	}
	//if (*str_total && str_total)
	//{
	//	if (ft_parse_line(str_total, *line))
	//		return (1);
	//}
	if (ret == 0 || ret == -1)
		return (ret);
	return (0);
}

/*bon le probleme ma variable static. 
 *
 *
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
