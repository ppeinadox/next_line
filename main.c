#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int i;
	int fd;
	
	i = 4;
	fd = open("/Users/patricia/ppatroclo/get_next_line/41_with_nl.txt", O_RDONLY);
	while (i >= 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
}
