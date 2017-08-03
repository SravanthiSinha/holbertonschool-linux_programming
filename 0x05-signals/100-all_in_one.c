#include "signals.h"

/**
 * sigaction_handler - handler for the signal SIGINT
 * @signum: signal number
 * @info: sinal info
 * @vp: pointer to user context
 * Return : void.
 */
void sigaction_handler(int signum, siginfo_t *info, void *vp)
{
	(void)vp;
	(void)signum;
	psiginfo(info, "Caught");
	fflush(stdout);
}

/**
 * all_in_one - A function that sets up a single handler for all the signals
 * Return: void.
 */
void all_in_one(void)
{
	struct sigaction act;
	int i;

	memset(&act, '\0', sizeof(act));
	act.sa_sigaction = &sigaction_handler;
	act.sa_flags = SA_SIGINFO;
	for (i = 1; i < 32; i++)
	{
		sigaction(i, &act, NULL);
	}
}
