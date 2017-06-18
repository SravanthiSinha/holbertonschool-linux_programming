#ifndef _OPTIONS_H_
#define _OPTIONS_H_

/**
 * struct Options - Options struct used to store the file options from input
 * @all : If -a option is given all =1 else 0
 * @almost_all : If -A option is given almost_all =1 else 0
 * @delimeter : If -1 option is given delimeter ="\n" else "  "
 * @reverse : If -r option is given almost_all =1 else 0
 * @long_format : If -l option is given long_format =1 else 0
 *
 */
typedef struct Options
{
	int all;
	int almost_all;
	char *delimeter;
	int reverse;
	int long_format;
} Options;

Options *inititate_options(char *options);
void free_options(Options *options);
#endif
