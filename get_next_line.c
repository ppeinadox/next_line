#include "get_next_line.h"
#include <stdio.h>

char *read_fd(int fd, ssize_t *n_bytes)
{
	char buf[BUFFER_SIZE + 1];
	char *buffer;

	*buf = 0;
	buffer = NULL;
	*n_bytes = read(fd, buf, BUFFER_SIZE);
	buf[*n_bytes] = '\0';
	if (*n_bytes < 1)
		return (NULL);
	else	
		buffer = ft_strdup(buf);
	return (buffer);
}

char *fill_static(int fd, char **stocked, ssize_t *n_bytes)
{
	char *line;
	char *aux;
	char *buf;
	
	line = NULL;
	aux = NULL;
	buf = NULL;
	if(!*stocked)
		return (NULL);
	while(!(ft_strchr(*stocked, '\n') || (*n_bytes = 0)))
	{
			buf = read_fd(fd, n_bytes);
			if(!buf)
				break;
			aux = ft_strjoin(*stocked, buf);
			if(!aux)
				return (free(*stocked), free(buf), NULL);
			free(*stocked);
			*stocked = aux;
			free(buf);
	}
	if(!line)
		line = looking_for_line(stocked, n_bytes);
	return(line);

}

char	*looking_for_position(char **stocked)
{
	char *position;

	position = NULL;	
	if (ft_strchr(*stocked, '\n'))
		position = ft_strchr(*stocked, '\n');
	else if (ft_strchr(*stocked, '\0'))
		position = ft_strchr(*stocked, '\0');
	return (position);
}

char	*looking_for_line(char **stocked, ssize_t *n_bytes)
{
	char *position;
	char *line;
	int end_stk;
	char *aux;
	
	line = NULL;
	end_stk = ft_strlen(*stocked);
	aux = NULL;
	position = looking_for_position(stocked);
	line = ft_substr(*stocked, 0, (position - *stocked + 1));
	if(!line)
		return (free(*stocked), NULL);
	if(*n_bytes == 0)
	{	
		free(*stocked);
		*stocked = NULL;
	}
	else
	{
		aux = ft_substr(*stocked, (position - *stocked + 1), end_stk);	
		free(*stocked);
		*stocked = aux;
	}
	return (line);
}

char *get_next_line(int fd)
{
	char *line;
	static char *stocked = NULL;
	ssize_t n_bytes = 1;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if(!stocked || stocked[0] == '\0')
	{	
		free (stocked);
		stocked = read_fd(fd, &n_bytes);
	}
	if (stocked && stocked[0] == '\0')
		return (free(stocked), NULL);
	line = fill_static(fd, &stocked, &n_bytes);
	if(!line)
		return (free(stocked), NULL);
	return(line);
}
