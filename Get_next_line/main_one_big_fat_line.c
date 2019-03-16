#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(void)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;

    system("mkdir -p sandbox");
	system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

	fd = open("sandbox/large_file.txt", O_RDONLY);
	fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	}

	close(fd);
	close(fd2);

	system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
	fd3 = open("sandbox/large_file.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	printf("%d\n", diff_file_size);
	close(fd3);

	return (0);
}
