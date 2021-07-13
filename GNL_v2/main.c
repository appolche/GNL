#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = 0;
	char *gnl;

	fd = open("text.txt", O_RDONLY);
	while ((gnl = get_next_line(fd)) != NULL)
	{
		printf("%s", gnl);
		free(gnl);
		gnl = NULL;
	}
	//  gnl = get_next_line(fd);
	//      printf("%s", gnl);
	return (0);
}
