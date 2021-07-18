
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h> //malloc
# include <unistd.h> //read

char    *get_next_line(int fd);
size_t    ft_strlen(const char *s);
int        ft_strchr(char *str, int c);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strdup(const char *src);
char    *ft_strjoin(char *s1, const char *s2);
char *ft_strtrim(char *src, int n);


#  define MAX_FD 10240 // 256 - Mac OS X comes with the 256 as the default limit for the number of the files open by a single process
//Programs utilizing I/O multiplex or non-blocking I/O on Mac OS X are by default restricted to 1024 file descriptors per process
//ulimit -a :file descriptors  10240

#  define BUFFER_SIZE 1

#endif
