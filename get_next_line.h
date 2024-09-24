# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42

#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char  *ft_strdup(char *s);
char *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char *read_fd(fd);
char *fill_static(char *buf, int fd);
char *looking_for_line(static char *stocked);
char *get_next_line(int fd)

# endif
