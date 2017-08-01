#include "signals.h"
/**
 * signals_block - A function that block a given set of signals from being
 * delivered to the current process
 * @signals: A 0 terminated array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 */
int signals_block(int *signals)
{
	int i = 0;
	sigset_t intmask;

	while (signals[i] != 0)
	{
		if (sigaddset(&intmask, signals[i]) < 0)
			return (-1);
		sigprocmask(SIG_BLOCK, &intmask, NULL);
		i++;
	}
	return (0);
}
