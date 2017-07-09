#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main(void)
{
    int fd1, fd2, fd3;
    char *line1;
    char *line2;
    char *line3;
    int i;

    fd1 = open("the_swing", O_RDONLY);
    fd2 = open("man_gcc", O_RDONLY);
    fd3 = open("man_cat", O_RDONLY);
    printf("---------THE SWING (first 5 lines)-----------\n");
    i = 0;
    while ((line1 = _getline(fd1)))
    {
        printf("%s\n", line1);
        free(line1);
        i++;
        if (i == 5)
        {
            break;
        }
    }
    printf("----------MAN GCC (first 5 lines)----------\n");
    i = 0;
    while ((line2 = _getline(fd2)))
    {
        printf("%s\n", line2);
        free(line2);
        i++;
        if (i == 5)
        {
            break;
        }
    }
    printf("-----------MAN CAT (first 5 lines)---------\n");
    i = 0;
    while ((line3 = _getline(fd3)))
    {
        printf("%s\n", line3);
        free(line3);
        i++;
        if (i == 5)
        {
            break;
        }
    }
    printf("---------THE SWING (END)-----------\n");
    while ((line1 = _getline(fd1)))
    {
        printf("%s\n", line1);
        free(line1);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    _getline(-1);
    printf("---------THE SWING (FULL-TEXT)-----------\n");
    fd1 = open("the_swing", O_RDONLY);
    while ((line1 = _getline(fd1)))
    {
        printf("%s\n", line1);
        free(line1);
    }
    close(fd1);
    return (EXIT_SUCCESS);
}
