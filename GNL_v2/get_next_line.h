#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strchr(char *str, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, const char *s2);

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
