#!/usr/bin/env python3
import sys
try:
    with open("file0.txt", "r") as f:
        file = f.read()
except IOError:
    sys.exit("file not found")

for i in file:
    print(i)
