#!/usr/bin/env python3
# substring1.py
# Mon, April 1 2019 14:18hrs
# This program compares two files
# and compares substrings between
# them, returning the substrings that
# they have in common, in a list.
list0 = []

file0, file1 = input("File 1: "), input("File 2: ")

try:
    with open(file0, "r") as f:
        first_file = f.read()
except FileNotFoundError:
    print(f"{file0} not found")

try:
    with open(file1, "r") as f:
        second_file = f.read()
except FileNotFoundError:
    print(f"{file1} not found")

# Prompts the user for the length of each substring
n = int(input("Enter substring length: "))

# Extracts the substrings from each string
def extract(str0, str1, x):
    """Takes a string of characters and an integer value of x,
    and breaks the string into substrings of length x. The
    function returns a list comprising of those substrings"""
    subs0, subs1, subs2 = [], [], []

    # Iterates over str0
    n = len(str0)
    for i in range(n):
        s = str0[i:int(i+x)]
        subs0.append(s)
        t = len(s)
        if t < x:
            subs0.pop()

    # Iterates over str1
    n = len(str1)
    for i in range(n):
        s = str1[i:int(i+x)]
        subs1.append(s)
        t = len(s)
        if t < x:
            subs1.pop()

    # Creates a list of similar substrings
    for i in subs0:
        if i in subs1 and i not in subs2:
            subs2.append(i)

    return subs2

list0 = extract(first_file, second_file, n)

for i in list0:
    print(i)