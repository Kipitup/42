/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:11:44 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 17:55:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line = NULL;
	int		fd = open("./tests/gnl10.txt", O_RDONLY);

	get_next_line(fd, &line);
	ft_memdel((void**)&line);
	close(fd);
//	sleep(0);
	return (0);
}
