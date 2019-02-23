/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:34 by amartino          #+#    #+#             */
/*   Updated: 2019/02/23 17:33:17 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_checks(const int fd, t_gnl_list *root)
{
	if (root && (root->fd != fd))
	{
		printf("\033[35;01mroot exist and fd are dfferent\033[00m\n");  //rose
		root->prev = root;
		root = root->next;
	}
	if (!root)
	{
		if (!(root = (t_gnl_list*)malloc(sizeof(t_gnl_list))))
			return (root = NULL);
		printf("\033[32;01m%p\033[00m\n", root->str_total);  //vert
		root->next = NULL;
		if (root->str_total)
		{
			printf("\033[32;01mstr->total exist\033[00m\n");  //vert
			ft_memset(root->str_total, 0, 1);
		}
		printf("\033[32;01mOK\033[00m\n");  //vert
		root->fd = fd;
	}
	if (fd < 0)
		return (root = NULL);
	printf("\033[33;01mbottom\033[00m\n");  //vert
	return (root);
}

int		ft_parse_line(t_gnl_list *alst, char **line)
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
			return (j);
		}
	}
	if (*(alst->ret) == 0 && ((j = ft_strlen(alst->str_total)) > 0))
	{
		if (!(*line = (char*)malloc(sizeof(char) * (j + 1))))
			return (0);
		*line = ft_memmove(*line, alst->str_total, j);
		(*line)[j] = '\0';
		return (j - 1);
	}
	return (0);
}

char	*ft_read_file(t_gnl_list *alst)
{
	int				i;
	char			buff[BUFF_SIZE + 1];

	while (*(alst->ret) > 0)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((*(alst->ret) = read(alst->fd, &buff, BUFF_SIZE)) == -1)
			return (NULL);
		buff[BUFF_SIZE] = '\0';
		if (!(alst->str_total))
			alst->str_total = ft_strdup(buff);
		else
			alst->str_total = ft_strjoin(alst->str_total, buff);
		i = -1;
		while ((alst->str_total)[++i])
			if ((alst->str_total)[i] == '\n')
			{
				printf("\033[34;01m%s\033[00m\n", alst->str_total);  //bleu
				return (alst->str_total);
			}
	}
	return (alst->str_total);
}

int		get_next_line(const int fd, char **line)
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
			root->str_total = root->str_total + j + 1;
			return (1);
		}
	}
	if ((root->str_total = ft_read_file(root)) == NULL)
		return (-1);
	if ((j = ft_parse_line(root, line)) != 0)
	{
		root->str_total = root->str_total + j + 1;
		return (1);
	}
	return (0);
}




/*
printf("\033[32;01mOK\033[00m\n");  //vert
printf("\033[33;01m%d\033[00m\n", root->ret);  //jaune
printf("\033[31;01m%s\033[00m\n", root->str_total);   //rouge
printf("\033[34;01m%s\033[00m\n", buff);  //bleu
 *
 *pb : dernier appelle de get_line, quand pas de \n a la fin il ne faut pas
 avancer de str_total + j + 1. (pas le +1)

 si pendant le read, il y a un probleme et que -1 est retourné => PB

 root->(*str_total) ??
*/
