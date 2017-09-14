#!/bin/bash
FILES="./tests/*"
i=0
for f in $FILES
do
  echo 'checking: '$f
  diff <(./1-hreadelf $f) <(readelf -W -S $f)
done
