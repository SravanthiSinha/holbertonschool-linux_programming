#!/bin/bash
FILES="./tests/elf_files/*"
i=0
for f in $FILES
do
  diff <(./hnm $f) <(nm -p $f)
  if [ $? -ne 0 ]
  then
    echo $f
  fi
done
