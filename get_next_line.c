#include "get_next_line.h"
#include <stdio.h>

static char *ft_tmpcpy(char *tmp, const char *line, int n)
{
    int i;

    i = 0;
    while (n)
    {
        tmp[i] = line[i];
        i++;
        n--;
    }
    tmp[i] = '\0';
    return (tmp);
}

static char *line_return(char *tmp, char **line, int n, char **buffer)
{
    tmp = malloc((n + 1) * sizeof(char));
    tmp = ft_tmpcpy(tmp, *line, n);
    *line = ft_strtrim(*line, n);
    free(*buffer);
    return (tmp);
}

static char *ft_fill_line(char *line, char *buffer)
{
    if (!line)
        line = ft_strdup(buffer);
    else
        line = ft_strjoin(line, buffer);
    return (line);
}

char *get_next_line(int fd)
{
    static char *line;
    char *buffer;
    char *tmp;
    int bite_was_read;
    int n;

    tmp = NULL;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || !buffer)
        return (NULL);
    while ((bite_was_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bite_was_read] = '\0';
        line = ft_fill_line(line, buffer);
        if ((n = ft_strchr(line, '\n')) >= 0)
            return (tmp = line_return(tmp, &line, n, &buffer));
        // free(buffer);
    }
    if (line && (n = ft_strchr(line, '\n')) >= 0)
        return (tmp = line_return(tmp, &line, n, &buffer));
    if (buffer)
        free(buffer);
    return (NULL);
}

int main()
{
    int fd = 0;
    char *gnl;

    fd = open("test.txt", O_RDONLY);
    while ((gnl = get_next_line(fd)) != NULL)
    {
        printf("%s", gnl);
        free(gnl);
        gnl = NULL;
    }
    sleep(1000);
    free(gnl);
    gnl = NULL;
    //  gnl = get_next_line(fd);
    //      printf("%s", gnl);
    return (0);
}
