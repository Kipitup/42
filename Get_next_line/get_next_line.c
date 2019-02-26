/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/02/26 17:13:32 by amartino         ###   ########.fr       */
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
			return (NULL);
		ft_bzero(root, sizeof(*root));
		root->fd = fd;
	}
	return (fd < 0 ? NULL : root);
}

int				ft_parse_line(t_gnl_list *alst, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (alst->str_total && (tmp = ft_strchr(alst->str_total, '\n')))
	{
		*line = ft_strsub(alst->str_total, 0, tmp - alst->str_total);
		tmp = ft_strdup(tmp + 1);
		ft_strdel(&alst->str_total);
		if (*tmp)
			alst->str_total = tmp;
		else
			ft_strdel(&tmp);
		return (1);
	}
	else if (alst->ret == 0 && ((ft_strlen(alst->str_total)) > 0))
	{
		*line = ft_strdup(alst->str_total);
		ft_strdel(&alst->str_total);
		return (1);
	}
	return (0);
}

static void		ft_read_file(t_gnl_list *alst)
{
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	tmp = NULL;
	while (alst->ret > 0)
	{
		if ((alst->ret = read(alst->fd, &buff, BUFF_SIZE)) == -1)
			return ;
		buff[alst->ret] = '\0';
		if (!(alst->str_total))
			alst->str_total = ft_strdup(buff);
		else
		{
			tmp = alst->str_total;
			alst->str_total = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
		if (alst->str_total && ft_strchr(alst->str_total, '\n'))
			return ;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_list	*root;

	if ((root = ft_checks(fd, root)) == NULL)
		return (-1);
	root->ret = 1;
	if (root->str_total && *(root->str_total))
		if (ft_parse_line(root, line))
			return (1);
	ft_read_file(root);
	if (root->ret == -1)
		return (-1);
	if (ft_parse_line(root, line))
		return (1);
	ft_strdel(&root->str_total);
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
