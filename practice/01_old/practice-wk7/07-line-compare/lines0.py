#!/usr/bin/env python3
# lines0.py
# Thur, Mar 28 2019 13:57hrs
# This program compares the text
# in two separate strings and returns
# the strings that are similar in both
# lists

str_a = "From days of long ago,\n\
from uncharted regions of the universe,\n\
comes a legend;\n\
the legend of Voltron, Defender of the Universe.\n\
I love that show."

str_b = "From days of long ago,\n\
from uncharted regions of the universe,\n\
comes a legend;\n\
the legend of Voltron, Defender of the Universe.\n\
I hate that show."

list_a, list_b, list_c = [], [], []

list_a = str_a.splitlines()
list_b = str_b.splitlines()

for line in list_a:
    if line in list_b and line not in list_c:
        list_c.append(line)

for i in list_c:
    print(i)