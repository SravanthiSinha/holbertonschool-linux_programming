#include "signals.h"

/**
 * print_hello - handler for the signal SIGINT
 * @signum: signal number
 * Return : void.
 */
void print_hello(int signum)
{
  printf("Hello! :)%d\n", signum);
}

/**
 * set_print_hello - a function that set a handler for the signal SIGINT
 * Return: 0 on success, or -1 on error.
 */
void set_print_hello(void)
{
  signal(SIGINT, print_hello);
  return;
}
