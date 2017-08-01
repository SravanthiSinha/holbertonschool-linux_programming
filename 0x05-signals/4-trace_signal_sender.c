#include "signals.h"

/**
 * termination_handler - handler for the signal SIGINT
 * @signum: signal number
 * @info: sinal info
 * @vp: pointer to user context
 * Return : void.
 */
void termination_handler(int signum, siginfo_t *info, void *vp)
{
	(void)vp;
	(void)signum;
	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - defines a handler for the signal SIGQUIT
 * (Control-\ in a shell)
 * Return: 0 on success, or -1 on error.
 */
int trace_signal_sender(void)
{
	struct sigaction new_action, old_action;

	/* Set up the structure to specify the new action. */
	new_action.sa_sigaction = termination_handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	return (sigaction(SIGQUIT, &new_action, &old_action));
}
