#!/bin/bash
gcc -shared -Wall -Werror -pedantic -Wextra -fPIC -o liball.so ./*.c
