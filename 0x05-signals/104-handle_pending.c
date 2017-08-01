#include "signals.h"
/**
 * handle_pending - a function that sets up a handler for all the pending
 * signals of the current process
 * @handler: A pointer to the handler function to set for the pending signals
 * Return: 0 on success, or -1 on error
 */
int handle_pending(void (*handler)(int))
{
	struct sigaction sigact;
	sigset_t waiting_mask;
	int i;

	sigpending(&waiting_mask);
	for (i = 1; i < 32; i++)
	{
		sigact.sa_flags = SA_SIGINFO;
		sigact.sa_handler = handler;
		sigaction(i, &sigact, NULL);
		if (sigaddset(&waiting_mask, i) < 0)
			return (-1);
	}
	return (0);
}
