#include "signals.h"

/**
 * termination_handler - handler for the signal SIGINT
 * @signum: signal number
 * Return : void.
 */
void termination_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_sigaction - a function that set a handler for the signal SIGINT
 * Return: 0 on success, or -1 on error.
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	/* Set up the structure to specify the new action. */
	sa.sa_handler = termination_handler;
	sigemptyset(&sa.sa_mask);
	/* Restart functions if interrupted by handler */
	sa.sa_flags = SA_RESTART;

	return (sigaction(SIGINT, &sa, NULL));
}
