#include "signals.h"

/**
 * sigset_init - A function that sets up a single handler for all the signals
 * @set: A pointer to the signal set to initialize
 * @signals: A 0 terminated array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	int i = 0;
	struct sigaction sigact;

	sigemptyset(set);
	while (signals[i] != 0)
	{
		sigact.sa_flags = SA_SIGINFO;
		sigact.sa_handler = SIG_IGN;
		sigaction(signals[i], &sigact, NULL);
		if (sigaddset(set, signals[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
