/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/04/08 11:51:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_list	*ft_lstadd_new_gnl(t_gnl_list *lst, int fd)
{
	t_gnl_list	*tmp;
	t_gnl_list	*new_lst;

	if (lst && lst->fd == fd)
		return (lst);
	if (!(new_lst = (t_gnl_list *)ft_memalloc(sizeof(t_gnl_list))))
		return (NULL);
	if (!lst)
	{
		lst = new_lst;
		lst->fd = fd;
		lst->next = lst;
		return (lst);
	}
	tmp = lst->next;
	lst->next = new_lst;
	lst->next->next = tmp;
	lst = lst->next;
	lst->fd = fd;
	lst->str_total = NULL;
	return (lst);
}

static t_gnl_list	*ft_checks(const int fd, t_gnl_list *root)
{
	t_gnl_list	*tmp;

	tmp = root;
	if (tmp && (tmp->fd != fd))
	{
		tmp = tmp->next;
		while (tmp && (tmp->fd != root->fd))
		{
			if (tmp && (tmp->fd == fd))
				return (tmp);
			tmp = tmp->next;
		}
	}
	if (!(tmp = ft_lstadd_new_gnl(tmp, fd)))
		return (NULL);
	return (tmp);
}

static int			ft_parse_line(t_gnl_list *alst, char **line)
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

static void			ft_read_file(t_gnl_list *alst)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

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
		if (ft_strchr(buff, '\n'))
			return ;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*root;

	if (fd < 0)
		return (-1);
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
