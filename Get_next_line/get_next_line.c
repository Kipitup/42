/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/03/16 23:15:16 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list		*ft_lstadd_new_gnl(t_gnl_list *lst, size_t size)
{
	t_gnl_list	*tmp;
	t_gnl_list	*new_lst;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	if (!(new_lst = ft_memalloc(sizeof(size))))
		return (NULL);
	lst->next = new_lst;
	lst->next->next = tmp;
	return (lst);
}

static t_gnl_list	*ft_checks(const int fd, t_gnl_list *root)
{
	t_gnl_list	*tmp;

	tmp = root;
	// if (root && root->fd)
	// 	printf("\033[34;01m%d\033[00m\n", root->fd);
	// if (root && root->next && root->next->fd)
	// 	printf("\033[35;01m%d\033[00m\n", root->next->fd);
	// if (root && root->next && root->next->next && root->next->next->fd)
	// 	printf("\033[36;01m%d\033[00m\n", root->next->next->fd);
	// if (root && root->next && root->next->next && root->next->next->next && root->next->next->next->fd)
	// 	printf("\033[36;01m%d\033[00m\n", root->next->next->next->fd);
	if (tmp && (tmp->fd != fd))
	{
		tmp = tmp->next;
		ft_putstr("0\n");
		printf("\033[34;01m%d\033[00m\n", tmp->fd); //SEG FAULT
		ft_putstr("0\n");
		printf("\033[33;01m%d\033[00m\n", root->fd);
		printf("\033[34;01m%d\033[00m\n", fd);
		while (tmp && (tmp->fd != root->fd))
			{
				// printf("\033[32;01m%d\033[00m\n", tmp->fd);
				// printf("\033[33;01m%d\033[00m\n", root->fd);
				// printf("\033[32;01m%d\033[00m\n", fd);
				// ft_putstr("b\n");
				ft_putstr("1\n");
				if (tmp && (tmp->fd == fd))
					return (tmp);
				// ft_putstr("c\n");
				tmp = tmp->next;
			}
		ft_putstr("d\n");
	}
	if (!tmp)
	{
		if (!(tmp = ft_memalloc(sizeof(t_gnl_list))))
			return (NULL);
		tmp->fd = fd;
		tmp->next = tmp;
	}
	else if (tmp->fd != fd)
	{
		// printf("\033[34;01m%d\033[00m\n", tmp->fd);
		if (!(tmp = ft_lstadd_new_gnl(tmp, (sizeof(t_gnl_list)))))
			return (NULL);
		tmp = tmp->next;
		tmp->fd = fd;
		printf("\033[32;01m[%d]\033[00m\n", tmp->fd);
		printf("\033[35;01m[%d]\033[00m\n", tmp->next->fd);
		printf("\033[36;01m[%d]\033[00m\n", tmp->next->next->fd);
		printf("\033[36;01m[%d]\033[00m\n", tmp->next->next->next->fd);
		tmp->str_total = NULL;
	}
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
	if (root)
		printf("\033[32;01m%d\033[00m\n", root->fd);
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
*/

// printf("\033[35;01m%p\033[00m\n", (void*)root);
// printf("\033[35;01m%p\033[00m\n", (void*)tmp);
// if (root && root->fd)
// 	printf("\033[34;01m%d\033[00m\n", root->fd);
// if (root && root->next && root->next->fd)
// 	printf("\033[35;01m%d\033[00m\n", root->next->fd);
// if (root && root->next && root->next->next && root->next->next->fd)
// 	printf("\033[36;01m%d\033[00m\n", root->next->next->fd);
// if (root && root->next && root->next->next && root->next->next->next && root->next->next->next->fd)
// 	printf("\033[36;01m%d\033[00m\n", root->next->next->next->fd);


/*
** static t_gnl_list	*ft_checks(const int fd, t_gnl_list *root)
** {
** 	t_gnl_list	*tmp;
** 	t_gnl_list	*tmp2;
**
** 	tmp = root;
** 	if (tmp && (tmp->fd != fd))
** 	{
** 		tmp = tmp->next;
** 		while (tmp && (tmp->fd != root->fd))
** 			{
** 				if (tmp && (tmp->fd == fd))
** 					return (tmp);
** 				tmp = tmp->next;
** 			}
** 	}
** 	if (!tmp)
** 	{
** 		if (!(tmp = ft_memalloc(sizeof(t_gnl_list))))
** 			return (NULL);
** 		tmp->fd = fd;
** 		tmp->next = tmp;
** 	}
** 	else if (tmp->fd != fd)
** 	{
** 		root = tmp->next;
** 		if (!(tmp2 = ft_memalloc(sizeof(t_gnl_list))))
** 			return (NULL);
** 		tmp->next = tmp2;
** 		tmp->next->fd = fd;
** 		tmp->next->str_total = NULL;
** 		tmp->next->next = root;
** 		tmp = tmp->next;
** 	}
** 	return (tmp);
** }
*/
