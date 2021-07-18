#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strcpy(char *dst, const char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char *ft_strtrim(char *src, int n)
{
    char *dst;
    int i;
    int len;

    i = 0;
    len = ft_strlen(src);
    dst = malloc((len - n + 1) * sizeof(char));
    while (src[n])
        dst[i++] = src[n++];
    dst[i] = '\0';
    free(src);
    src = NULL;
    return (dst);
}

int ft_strchr(char *str, int c)
{
    int i;

    i = 0;
    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == c)
            return (i + 1);
        i++;
    }
    return (-1);
}

char *ft_strdup(const char *src)
{
    char *dst;

    dst = malloc(sizeof(*dst) * (ft_strlen(src) + 1));
    if (!dst)
        return (0);
    dst = ft_strcpy(dst, src);
    return (dst);
}

char *ft_strjoin(char *s1, const char *s2)
{
    char *s3;
    int i;
    int j;

    if (!s1 || !s2)
        return (0);
    s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (NULL == s3)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s3[j + i] = s2[j];
        j++;
    }
    free(s1);
    s1 = NULL;
    s3[j + i] = '\0';
    return (s3);
}
