/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_louis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:01:33 by amartino          #+#    #+#             */
/*   Updated: 2019/03/25 16:44:01 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
			ft_putendl(line);
		ft_strdel(&line);
	}
	close (fd);
	ft_strdel(&line);
	return (0);
}
