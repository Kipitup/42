/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:52:30 by amartino          #+#    #+#             */
/*   Updated: 2018/11/09 15:44:59 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *str)
{
	int		fd;
	int		len;
	char	tmp[1001];

	if ((fd = open(str, O_RDWR)) != -1)
	{
		while ((len = read(fd, tmp, 1000)))
		{
			tmp[len] = '\0';
			write(1, tmp, len);
		}
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc == 2)
		ft_display_file(argv[1]);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
