#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>



/**
 * sig_handler - handler for the signal SIGINT
 * @signum: signal number
 * Return : void.
 */
void sig_handler(int signum)
{
	printf("Caught %d\n", signum);
	printf("Signal received\n");
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
/**
 * main -  a program that sets a handler for the signal `SIGINT,
 * and exits right after the signal is received and handled
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	if (handle_signal() < 0)
		return (EXIT_FAILURE);

		pause();
	return (EXIT_SUCCESS);
}
