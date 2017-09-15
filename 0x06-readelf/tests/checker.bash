#!/bin/bash
FILES="./tests/elf_files/*"
i=0
for f in $FILES
do
  echo 'checking: '$f
  diff <(./$1-hreadelf $f) <(readelf -W -$2 $f)
done
