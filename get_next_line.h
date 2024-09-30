# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
char  *ft_strdup(char *s);
char *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char *read_fd(int fd, ssize_t *n_bytes);
char *fill_static(int fd, char **stocked, ssize_t *n_bytes);
char *looking_for_line(char **stocked);
char *get_next_line(int fd);

# endif
