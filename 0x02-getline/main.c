#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - entry point.
 *
 * Return: always 0.
 */
#include "_getline.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("main.c", 0);
    while ((line = _getline(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
