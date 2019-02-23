/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 19:51:31 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_multi_fd(const int fd, t_gnl_list *root)
{
	t_gnl_list	*tmp;

	if (root && (root->fd != fd))
	{
		tmp = root;
		while (tmp->prev)
		{
			tmp = tmp->prev;
			if (tmp->fd == fd)
				return (tmp);
		}
		tmp = root;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->fd == fd)
				return (tmp);
		}
		root->prev = root;
		root = root->next;
	}
	return (root);
}

t_gnl_list	*ft_checks(const int fd, t_gnl_list *root)
{
	root = ft_multi_fd(fd, root);
	if (!root)
	{
		if (!(root = (t_gnl_list*)malloc(sizeof(t_gnl_list))))
			return (root = NULL);
		ft_bzero(root, sizeof(*root));
		root->fd = fd;
	}
	if (fd < 0)
		return (root = NULL);
	return (root);
}

int			ft_parse_line(t_gnl_list *alst, char **line)
{
	int		j;

	j = -1;
	while (alst->str_total[++j])
	{
		if (alst->str_total[j] == '\n')
		{
			if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
				return (0);
			*line = ft_memmove(*line, alst->str_total, j);
			(*line)[j] = '\0';
			return (j + 1);
		}
	}
	if (*(alst->ret) == 0 && ((j = ft_strlen(alst->str_total)) > 0))
	{
		if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
			return (0);
		*line = ft_memmove(*line, alst->str_total, j);
		(*line)[j] = '\0';
		return (j);
	}
	return (0);
}

//pb quand je veux free temp

char		*ft_read_file(t_gnl_list *alst)
{
	int				i;
	char			*temp;
	char			buff[BUFF_SIZE + 1];

	temp = NULL;
	while (*(alst->ret) > 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((*(alst->ret) = read(alst->fd, &buff, BUFF_SIZE)) == -1)
			return (NULL);
		buff[BUFF_SIZE] = '\0';
		if (!(alst->str_total))
			alst->str_total = ft_strdup(buff);
		else
		{
			temp = alst->str_total;
		//	printf("\033[33;01m%p\033[00m\n", alst->str_total);  //jaune
			alst->str_total = ft_strjoin(temp, buff);
		//	free(temp);
		//	printf("\033[34;01m%p\033[00m\n", alst->str_total);  //jaune
		}
		i = -1;
		while ((alst->str_total)[++i])
		{
			if ((alst->str_total)[i] == '\n')
			{
				return (alst->str_total);
			}
		}
	}
	return (alst->str_total);
}

int			get_next_line(const int fd, char **line)
{
	int					tmp;
	int					j;
	static t_gnl_list	*root;

	tmp = 1;
	if ((root = ft_checks(fd, root)) == NULL)
		return (-1);
	root->ret = &tmp;
	if (root->str_total && *(root->str_total))
	{
		if ((j = ft_parse_line(root, line)) != 0)
		{
			root->str_total = root->str_total + j;
			return (1);
		}
	}
	if ((root->str_total = ft_read_file(root)) == NULL)
		return (-1);
	if ((j = ft_parse_line(root, line)) != 0)
	{
		root->str_total = root->str_total + j;
		return (1);
	}
	return (0);
}

/*
**printf("\033[32;01mOK\033[00m\n");  //vert
**printf("\033[33;01m%d\033[00m\n", root->ret);  //jaune
**printf("\033[31;01m%s\033[00m\n", root->str_total);   //rouge
**printf("\033[34;01m%s\033[00m\n", buff);  //bleu
**
** pb : dernier appelle de get_line, quand pas de \n a la fin il ne faut pas
** avancer de str_total + j + 1. (pas le +1)
**
** si pendant le read, il y a un probleme et que -1 est retourné => PB
**
** root->(*str_total) ??
*/
