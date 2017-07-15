#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - entry point.
 *
 * Return: always 0.
 */
#include "_getline.h"

int main(void) {
  int fd, fd2, fd3;
  char *line, *line2, *line3;

  fd = open("normal_0", O_RDONLY);
  fd2 = open("normal_1", O_RDONLY);
  fd3 = open("the_swing", O_RDONLY);
  do {
    if ((line = _getline(fd))) {
      printf("%s\n", line);
      free(line);
    }
    if ((line2 = _getline(fd2))) {
      printf("%s\n",line2);
      free(line2);
    }
    if ((line3 = _getline(fd3))) {
      printf("%s\n", line3);
      free(line3);
    }
  } while (line || line2 || line3);
  close(fd);
  close(fd2);
  close(fd3);
  _getline(-1);
  return (0);
}
