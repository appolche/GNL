#include <stdio.h>
#include "get_next_line.h"

int main()
{
    char *line;
    int fd;

    fd = open("test.txt", O_RDONLY);
    while((line = get_next_line(fd)))
    {
        printf("%s", line);
    }
    printf("%s\n", line);
    free (line);
    close (fd);
    return(0);
}