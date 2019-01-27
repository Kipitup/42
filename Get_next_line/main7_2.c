/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:20:07 by amartino          #+#    #+#             */
/*   Updated: 2019/01/27 19:00:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;
	int		count_lines;
	int		errors;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 2)
		{
			count_lines = 0;
			errors = 0;
			line = NULL;
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				if (count_lines == 0 && ft_strcmp(line, "1234567") != 0)
					errors++;
				if (count_lines == 1 && ft_strcmp(line, "abcdefgh") != 0)
						errors++;
				count_lines++;
				if (count_lines > 50)
					break ;
			}
			close(fd);
			if (count_lines != 2)
				printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
			if (errors > 0)
				printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
			if (count_lines == 2 && errors == 0)
				printf("OK\n");
		}
		else
			printf("An error occured while opening file %s\n", av[1]);
	}
	return (0);
}
