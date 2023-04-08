#! usr/bin/env python3
import sys

def get_int(word):
    i = int(input(word))
    if i is None:
        sys.exit(1)
    return i

values = [12, 98, 0]

while True:
    number = get_int("number: ")

    values.insert(0, number)

print(values)