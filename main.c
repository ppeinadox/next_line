#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int i;
	int fd;
	char *line;

	line = NULL;	
	i = 10;
	fd = open("/mnt/c/Users/User/Desktop/42/get_next_line/41_with_nl.txt", O_RDONLY);
	while (i >= 0)
	{
		line =  get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
}
