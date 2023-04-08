#! usr/bin/env python3
import sys

values = [12, 98, 0]

while True:
    number = int(input("number: "))
    if number == sys.maxsize:
        break

    values.insert(0, number)

print(values)