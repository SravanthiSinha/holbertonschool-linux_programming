#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

#define LINE_LEN 21

/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main(void)
{
    int fd;
    char *line;
    int i;

    fd = open("zero", O_RDONLY);
    if (-1 == fd)
    {
        fprintf(stderr, "nop\n");
        return (EXIT_FAILURE);
    }
    while ((line = _getline(fd)))
    {
        for (i = 0; i < LINE_LEN; i++)
        {
            /*if (i)
            {
                printf(" ");
            }*/
            printf("%c", line[i]);
        }
        printf("\n");
        free(line);
    }
    close(fd);
    return (EXIT_SUCCESS);
}
