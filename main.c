#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int i;
	int fd;
	char *line;
	
	i = 10;
	fd = open("/Users/macuser/42/GNL/41_with_nl.txt", O_RDONLY);
	while (line =! NULL)
	{
		line =  get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
}
