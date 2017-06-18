#ifndef _OPTIONS_H_
#define _OPTIONS_H_

/**
 * struct Options - Options struct used to store the file options from input
 * @all : If -a option is given all =1 else 0
 * @delimeter : If -1 option is given delimeter ="\n" else "  "
 */
typedef struct Options
{
	int all;
  char *delimeter;
} Options;

Options *inititate_options(char *options);
void free_options(Options *options);
#endif
