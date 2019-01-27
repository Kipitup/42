/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:19:50 by amartino          #+#    #+#             */
/*   Updated: 2019/01/27 20:18:28 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int 	get_next_line(const int fd, char **line);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strclr(char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif
