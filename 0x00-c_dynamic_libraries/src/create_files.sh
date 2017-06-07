#!/bin/bash
while IFS='' read -r line || [[ -n "$line" ]]; do
     echo "$line" > $(echo "$line" | cut -d "(" -f1 |rev| cut -d " " -f1|rev| cut -d "*" -f2 |awk '{print $1".c"}')
done < "$1"
