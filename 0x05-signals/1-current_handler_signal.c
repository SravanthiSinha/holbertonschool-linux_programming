#include "signals.h"

/**
 * current_handler_signal - a function that retrieves the current handler of
 * the signal SIGINT.
 * Return: void.
 */
void (*current_handler_signal(void))(int)
{
	void (*old_handler)(int) = NULL;

	old_handler = signal(SIGINT, print_hello);
	if (old_handler == SIG_ERR)
		return (NULL);
	return (old_handler);
}
