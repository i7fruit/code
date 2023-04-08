#! usr/bin/env python3
import sys

def get_int(word):
    i = int(input(word))
    if i == 2147483647:
        return i
    return i

values = [12, 98, 0]

while True:
    number = get_int("number: ")
    if number == 2147483647:
        break

    values.insert(0, number)

print(values)