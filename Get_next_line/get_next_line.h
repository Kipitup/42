#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int 	get_next_line(const int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strclr(char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#endif
