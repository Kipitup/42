/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:50 by amartino          #+#    #+#             */
/*   Updated: 2019/02/26 16:20:34 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 150

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_gnl_list
{
	int					fd;
	int					ret;
	char				*str_total;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}				t_gnl_list;

int				get_next_line(const int fd, char **line);

#endif
