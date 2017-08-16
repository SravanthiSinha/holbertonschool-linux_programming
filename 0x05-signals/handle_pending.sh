#!/bin/sh
for i in `seq 1 8`
do
kill "-$i" "$1" >/dev/null 2>&1
done
for i in `seq 11 15`
do
kill "-$i" "$1" >/dev/null 2>&1
done
kill -10 "$1" >/dev/null 2>&1
