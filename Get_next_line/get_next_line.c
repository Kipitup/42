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

int		ft_open(const char *av)
{
	int		file;

	if (-1 == (file = open(av, O_RDONLY)))
		return (ft_error("File can't be opened.\n"));
	return (file);
}

int		ft_read(int file_descriptor)
{
	char	reader;
	int		buffer;
	int		secure;

	secure = 0;
	buffer = 1 * sizeof(char);
	secure = read(file_descriptor, &reader, buffer);
	if (secure < 0)
		return (ft_error("Error during reading process\n"));
	while (secure == buffer)
	{
		ft_putchar(reader);
		secure = read(file_descriptor, &reader, buffer);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		file_descriptor;
	int		i;

	if (ac < 2)
		ft_error("File name missing.\n");
	else if (ac > 2)
		ft_error("Too many arguments.\n");
	else
	{
		i = 0;
		if (!(file_descriptor = ft_open(av[1])))
			return (0);
		if (!ft_read(file_descriptor))
			return (0);
		if (-1 == close(file_descriptor))
			return (ft_error("Error while closing the file\n"));
	}
	return (0);
}
