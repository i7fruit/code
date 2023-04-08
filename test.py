#! usr/bin/env python3
import sys

def get_int(word):
    i = int(input(word))
    if not i:
        return sys.maxsize
    return i

values = [12, 98, 0]

while True:
    number = get_int("number: ")
    if number == sys.maxsize:
        break

    values.insert(0, number)

print(values)