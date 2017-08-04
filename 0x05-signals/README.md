# 0x05. C - Signals

### System programming & Algorithm ― Linux programming


* TASK 0: A function that set a handler for the signal SIGINT using signal()

  File: 0-handle_signal.c

* TASK 1: A function that retrieves the current handler of the signal SIGINT

  File: 1-current_handler_signal.c

* TASK 2: A function that set a handler for the signal SIGINT using sigaction()

  File: 2-handle_sigaction.c

* TASK 3: A function that retrieves the current handler of the signal SIGINT

  File: 3-current_handler_sigaction.c

* TASK 4: A function that defines a handler for the signal SIGQUIT (Control-\ in a shell)

  File: 4-trace_signal_sender.c

* TASK 5: A program that prints a description of a given signal

  File: 5-signal_describe.c

* TASK 6: A program that sets a handler for the signal `SIGINT`, and exits right after the signal is received and handled

  File: 6-suspend.c

* TASK 7: A program that sends the signal SIGINT to a process, given its PID

  File: 7-signal_send.c

* TASK 8: A sh script that sends the signal SIGQUIT to a process, given its PID

  File: 8-signal_send.sh

* TASK 9: A sh script that set a handler for the signals SIGABRT, SIGIO and SIGTERM

  File: 9-handle_signal.sh

* TASK 10: A function that tests if a process exists, given its PID.

  File: 10-pid_exist.c

* TASK 11: A blog post about [signals](https://medium.com/@SravanthiSinha/lets-signal-b0378c9a9928)
 

* TASK 12: A function that sets up a single handler for all the signals

  File: 100-all_in_one.c

* TASK 13: A function that initializes a sigset.

  File: 101-sigset_init.c

* TASK 14: A function that block a given set of signals from being delivered to the current process

  File: 102-signals_block.c

* TASK 15: A function that unblock a given set of signals from being delivered to the current process

  File: 103-signals_unblock.c

* TASK 16: A function that sets up a handler for all the pending signals of the current process

  File: 104-handle_pending.c

### Useful Resources:

https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html#Signal-Handling

http://www.comptechdoc.org/os/linux/programming/linux_pgsignals.html

https://doc.lagout.org/programmation/unix/The%20Linux%20Programming%20Interface.pdf

https://stackoverflow.com/questions/9152979/check-if-process-exists-given-its-pid/9153003

https://www.ibm.com/support/knowledgecenter/en/ssw_i5_54/apis/sigeset.htm
