#!/usr/bin/python3

from itertools import zip_longest

files = [open(filename) for filename in ['normal_0','normal_1','the_swing']]

for lines in zip_longest(*files, fillvalue=''):
    print("".join(lines), end="")
