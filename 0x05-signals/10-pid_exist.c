#include <errno.h>
#include <signal.h>
/**
 * pid_exist - a function that tests if a process exists, given its PID.
 * @pid: pid to look for
 * Return:  1 if the process with the PID pid exists, or 0 otherwise.
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) == 0 ? 1 : (errno == ESRCH ? 0 : 1));
}
