#include "signals.h"

/**
 * sig_handler - handler for the signal SIGINT
 * @signum: signal number
 * Return : void.
 */
void sig_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_signal - a function that set a handler for the signal SIGINT
 * Return: 0 on success, or -1 on error.
 */
int handle_signal(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		return (-1);
	return (0);
}
