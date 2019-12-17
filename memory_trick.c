#include <stdio.h>

int	main(int ac, char **av)
{
	//(void)ac;
	//(void)av;
	long	tab[2] = {42, 38};
	char	*str;

	printf("%s\n%s\n", *((char **)tab[-2]), av[0]);

	printf("addr of av:   \t\t%p\n", av);
	printf("addr of tab[-2]:\t%p\n", tab[-2]);
	printf("addr of tab:     \t%p\n", tab);
	printf("addr of av[0]:\t\t%p\n", av[0]);

	// str = *((char **)tab[-2]);
	// printf("%s\n%s\n", str, av[0]);
	// str[0] = 'H';
	// str[1] = 'A';
	// str[2] = 'C';
	// str[3] = 'K';
	// // str[4] = '\0';
	// printf("%s\n", av[0]);
	//printf("%s\nptr: %s\n", (char *)tab[-2], ptr);
	return (0);
}

/*

 addr  val
 | 24  |    |
|    |   
| 23 | 500|  ptr
| 22 |'\0'|
| 21 | 'o'|
| 20 | 'h'|
| 19 | 20 | ptr2
|    |    |
|    |    |
|    |    |
|    |    |
|    |    |
|    |    |
| 500| h  |  
| 501| o  |
| 502|'\0'|


	
	printf("%s\n%s\n", (str = (*((char **)tab[-2]))), av[0]);
	str[0] = 'H';
	str[1] = 'A';
	str[2] = 'C';
	str[3] = 'K';
	str[4] = '\0';
	printf("%s\n", av[0]);


void (char *f, ...))*/

