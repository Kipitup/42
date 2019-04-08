/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:50 by amartino          #+#    #+#             */
/*   Updated: 2019/04/03 22:43:14 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 50000

# include "libft/libft.h"

typedef struct	s_gnl_list
{
	struct s_gnl_list	*next;
	char				*str_total;
	int					fd;
	int					ret;
}				t_gnl_list;

int				get_next_line(const int fd, char **line);

#endif
