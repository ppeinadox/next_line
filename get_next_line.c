#include "get_next_line.h"

char *read_fd(fd)
{
	char buf[BUFFER_SIZE + 1];
	ssize_t n_bytes;
	
	n_bytes = read(fd, buf, BUFFER_SIZE);
	if (n_bytes < 1)
		return (NULL);

	return (buf);
}

char *fill_static(char *buf, int fd)
{
	static char *stocked;

	if (!stocked)
		stocked = ft_strdup(buf);
	if(!stocked)
		return (NULL);
	while (!line)
	{
		line = looking_for_line(stocked);
		if(!line)
		{
			buf = read_fd(fd);
			aux = ft_strjoin(buf, stocked);
			stocked = ft_strdup(aux);
			free(aux);
		}
	}
	return(line);

}

char *looking_for_line(static char *stocked)
{
	char *position;
	char *line;
	int end_stk;
	
	line = NULL;
	position = ft_strchr(stocked, '\n');
	end_stk = ft_strlen(stocked);
	if(!position)
		ft_strchr(stocked, '\0');
	if(position)
	{
		line	= ft_substr(stocked, 0, position - stocked);
		stocked = ft_substr(stocked, position - stocked, end_stk);
	}

	return(line);
}

char *get_next_line(int fd)
{
	if (!fd || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = read_fd(fd);
	if (!buf)
		return(NULL);
	line = fill_static(buf, fd);
	if(!line)
		return(NULL);
	return(line);

}
