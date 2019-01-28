/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:07 by amartino          #+#    #+#             */
/*   Updated: 2019/01/28 18:40:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	//int		count_line;
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
		while ((i = get_next_line(fd, &line)) > 0)
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
