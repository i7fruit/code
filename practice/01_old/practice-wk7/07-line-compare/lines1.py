#!/usr/bin/env python3
# lines1.py
# Thur, Mar 28 2019 14:14hrs
# This program compares two files
# line by line and returns a list
# containing lines that both files
# have in common.
from time import sleep
list_a = []
list_b = []
list_c = []

try:
    with open("water0.txt", "r") as f:
        for line in f:
            list_a.append(line)
except FileNotFoundError:
    print("No such file")

try:
    with open("water1.txt", "r") as f:
        for line in f:
            list_b.append(line)
except FileNotFoundError:
    print("No such file")

for i in list_a:
    if i in list_b and i not in list_c:
        list_c.append(i.rstrip())
        if i == "\n":
            list_c.pop()

for i in list_c:
    print(i)