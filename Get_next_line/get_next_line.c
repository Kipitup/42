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

void	ft_strclr(char *s)
{
	if (s != NULL)
		while (*s)
			*(s++) = 0;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((char*)dest > (char*)src)
		while (n-- > i)
			((char*)dest)[n] = ((char*)src)[n];
	else
		while (i++ < n)
			((char*)dest)[i - 1] = ((char*)src)[i - 1];
	return (dest);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*exact;

	if (!(exact = (char*)malloc(sizeof(char) * (++size))))
		return (NULL);
	while (size > 0)
		exact[--size] = '\0';
	exact[0] = '\0';
	return (exact);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	size1;
	int	size2;
	int	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char*)ft_strnew(size1 + size2)))
		return (NULL);
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i = -1;
	while (++i < size2)
		str[i + size1] = s2[i];
	str[size1 + size2] = '\0';
	return (str);
}

/*void		ft_display_line(char *s)
{
	write(1, s, ft_strlen(s));
}*/

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str_total;
	int		i;
	int		tmp;
	int		j;

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
	int	file_descriptor;
	int	i;
	char	*line;

	if (ac < 2)
		return 0;
	else if (ac > 2)
		return 0;
	else
	{
		i = 0;
		if (!(file_descriptor = open(av[1], O_RDONLY)))
			return (0);
		while ((i = get_next_line(file_descriptor, &line)))
		{
			ft_display_line(line);
			printf("\n");
		}
		if (-1 == close(file_descriptor))
			return 0;
	}
	return (0);
}
//printf("\033[34;01m%s\033[00m\n", *line);
*/
