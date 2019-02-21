/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:07 by amartino          #+#    #+#             */
/*   Updated: 2019/02/20 11:13:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		fd_2;
	int		i;
	char	*line;
	char	*line_2;

	if (ac > 1)
	{
		i = 0;
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		if (!(fd_2 = open(av[2], O_RDONLY)))
			return (0);
		i = get_next_line(fd_2, &line_2);
		printf("line 2 : %s", line_2);
		printf("\n");
		while ((i = get_next_line(fd, &line)))
		{
			printf("line : %s", line);
			printf("\n");
		}
	//	i = get_next_line(fd_2, &line_2);
	//	printf("line 2 : %s", line_2);
	//	printf("\n");
		if (-1 == close(fd))
			return 0;
	}
	return (0);
}
//printf("\033[34;01m%s\033[00m\n", line);
