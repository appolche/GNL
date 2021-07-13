#include "get_next_line.h"

static char	*ft_strtrim(char *line, int n)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	dst = malloc((len - n + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (line[n])
		dst[i++] = line[n++];
	dst[i] = '\0';
	free(line);
	line = NULL;
	return (dst);
}

static char	*ft_tmpcpy(char *tmp, const char *line, int n)
{
	int	i;

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

static char	*line_return(char **line, int n, char **buffer)
{
	char *tmp;
	
	tmp = NULL;
	tmp = malloc((n + 1) * sizeof(char));
	if (!tmp)
		return(NULL);
	tmp = ft_tmpcpy(tmp, *line, n);
	*line = ft_strtrim(*line, n);
	free(*buffer);
	return (tmp);
}

static char	*ft_fill_line(char *line, char *buffer)
{
	if (line)
		line = ft_strjoin(line, buffer);
	else
		line = ft_strdup(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			byte_read;
	int			n;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || byte_read <= 0)
		return (NULL);
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		line = ft_fill_line(line, buffer);
		n = ft_strchr(line, '\n');
		if (n >= 0)
			return (line_return(&line, n, &buffer));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
			return (NULL);
	}
	n = ft_strchr(line, '\n');
	if (line && n >= 0)
		return (line_return(&line, n, &buffer));
	else if (line && n < 0)
		return (line);
	if (buffer)
		free(buffer);
	return (NULL);
}
