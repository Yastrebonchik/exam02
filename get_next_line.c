#include "get_next_line.h"
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char s2)
{
    char *result;

    //write(1, "inside strjoin\n", 15);
    int i = 0;
    if (s1 == NULL)
        result = (char*)malloc(sizeof(char) + 2);
    else
        result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 2));
    // write(1, "middle of strjoin\n", 18);
    if (s1 == NULL)
    {
        result[i] = s2;
        result[i + 1] = '\0';
    }
    else
    {
        while (s1[i] != '\0')
        {
            //write(1, "tic\n", 4);
            result[i] = s1[i];
            i++;
        }
        // write(1, "end of strjoin\n", 15);
        result[i++] = s2;
        result[i] = '\0';
    }
    // write(1, "end of strjoin\n", 15);
    return (result);
}

int get_next_line(char **line)
{
    int     fd;
    char    buffer[1];
    int     i;
    char    *collat;

    fd = 0;
    i = 0;
    if (*line != NULL)
    {
        free(*line);
        *line = NULL;
    }
    if (read(fd, buffer, 0) == -1)
        return (-1);
    //write(1, "before read\n", 12);
    while (read(fd, buffer, 1) != 0)
    {
        collat = ft_strjoin(*line, '\0');
        free(*line);
        *line = ft_strjoin(collat, buffer[0]);
        free(collat);
        // printf("%s\n", *line);
        // printf("%d\n", i);
        if ((*line)[i] == '\n')
        {
            (*line)[i] = '\0';
            return(1);
        }
        // printf("end of read\n");
        i++;
    }
    return (0);
}