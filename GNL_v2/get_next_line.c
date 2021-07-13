#include "get_next_line.h"

static char	*ft_strtrim(char *src, int n)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dst = malloc((len - n + 1) * sizeof(char));
	if (!dst)
		return(NULL);
	while (src[n])
		dst[i++] = src[n++];
	dst[i] = '\0';
	if (src)
	{
		free(src);
		src = NULL;
	}
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

static char	*tmp_line_return(char **line, int n, char **buffer)
{
	char		*tmp;

	tmp = NULL;
	tmp = malloc((n + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_tmpcpy(tmp, *line, n);
	*line = ft_strtrim(*line, n);
	if (*buffer)
		free(*buffer);
	return (tmp);
}

/*static char	*ft_fill_line(char *line, char *buffer)
{

}*/

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			n;
	int			byte_read;
	char		*tmp;

	n = 0;
	tmp = NULL;
	buffer = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || !buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		if (!line || *line == '\0')
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		n = ft_strchr(line, '\n');
		if (n >= 0)
			return (tmp_line_return(&line, n, &buffer));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		/*if (byte_read < 0)
	{
		free(line);
		free(buffer);
		if (tmp)
			free(tmp);
		return (NULL);
	}*/
	}
	if (line)
	{
		n = ft_strchr(line, '\n');
		if (n >= 0)
			return (tmp_line_return(&line, n, &buffer));
		else if (n < 0)
		{
			tmp = ft_strdup(line);
			free (line);
			line = NULL;
			if (buffer)
				free(buffer);
			return (tmp);
		}
	}
	if (buffer)
		free(buffer);
	return (NULL);
}