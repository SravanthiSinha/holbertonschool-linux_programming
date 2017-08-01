#include "signals.h"

/**
 * current_handler_sigaction - a function that retrieves the current handler of
 * the signal SIGINT.
 * Return:  A pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction curr_act;

	if (sigaction(SIGINT, NULL, &curr_act) < 0)
		return (NULL);
	return (curr_act.sa_handler);
}
