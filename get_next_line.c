char *read_fd(fd)
{
	char buf[BUFFER_SIZE + 1];
	ssize_t n_bytes;
	
	n_bytes = read(fd, buf, BUFFER_SIZE);
	if (n_bytes = -1)
		return (NULL);
	return (buf);
}

char *fill_static(char *buf)
{
	static char *stocked;

	if (!stocked)
		stocked = ft_strdup(buf);
	else
		stocked = ft_strjoin(stocked, buf)
	if(!stocked)
		return (NULL);
	line = looking_for_line;
	if (!line)
		return(NULL);
}

char *looking_for_line(char *stocked)
{
	char *position;
	char *line;
	
	line = NULL;
	if(position = ft_strchr(stocked, "\n"))
	{
		line	= ft_substr(stocked, 0, position - stocked);
	}
	return(line);
}

char *get_next_line(int fd)
{
	if (!fd || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = read_fd(fd);
}
