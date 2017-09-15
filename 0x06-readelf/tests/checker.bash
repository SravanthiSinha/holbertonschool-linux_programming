#!/bin/bash
FILES="./tests/elf_files/*"
i=0
for f in $FILES
do
  diff <(./$1-hreadelf $f) <(readelf -W -$2 $f) >/dev/null
  if [ $? -ne 0 ]
  then
    echo $f
  fi
done
