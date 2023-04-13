#!usr/bin/env python3
import sys

def main():
    values = [12, 98, 0]

    while True:
        number = get_int("number: ")

        if number == sys.maxsize:
            break

        values.insert(0, number)

    print(values)

def get_int(word):
    try:
        i = int(input(word))
        return i
    except EOFError:
        return sys.maxsize

if __name__ == "__main__":
    main()