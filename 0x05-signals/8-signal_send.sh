#!/bin/sh
#A sh script that sends the signal SIGQUIT to a process, given its PID
if [ "$#" -ne 1 ]; then
    echo "Usage: ./8-signal_send <pid>"
    exit 1
fi
if kill -s QUIT "$1" >/dev/null 2>&1; then
    exit 0
else
  exit 1
fi
