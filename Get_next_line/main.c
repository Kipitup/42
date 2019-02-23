/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:07 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 12:00:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		fd_2;
	int		fd_3;
	int		i;
	int		j;
	int		k;
	char	*line;
//	char	*line_2;
//	char	*line_3;

	if (ac > 1)
	{
		i = 0;
		j = 0;
		k = 0;
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		if (!(fd_2 = open(av[2], O_RDONLY)))
			return (0);
		if (!(fd_3 = open(av[3], O_RDONLY)))
			return (0);
	//	i = get_next_line(fd_2, &line_2);
	//	printf("line 2 : %s", line_2);
	//	printf("\n");
		while ((j = get_next_line(fd, &line)))
		{
			printf("line : %s", line);
			printf("\n");
		}
	//	k = get_next_line(fd_3, &line_3);
	//	printf("line 2 : %s", line_3);
	//	printf("\n");
	//	i = get_next_line(fd_2, &line_2);
	//	printf("line 2 : %s", line_2);
	//	printf("\n");
		if (-1 == close(fd))
			return 0;
	}
	return (0);
}
//printf("\033[34;01m%s\033[00m\n", line);
