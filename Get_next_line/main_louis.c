/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_louis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:01:33 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 18:02:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	printf("\n\n");
	if (argc == 2)
		close(fd);
}
